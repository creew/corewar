/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:19:14 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include "ft_printf.h"

void		get_double_val(t_print *print, va_list *ptr, t_fpoint *fdata)
{
	t_bldouble	ld;
	long		exp;

	if (print->lenmod == LENMOD_BL)
		ld.val = va_arg(*ptr, t_ldouble);
	else
		ld.val = va_arg(*ptr, double);
	fdata->exp = ld.bldbl.exp;
	fdata->is_neg = ld.bldbl.sign;
	fdata->mant = ld.bldbl.man;
	exp = ld.bldbl.exp - 16382;
	fdata->exp = exp;
	if (exp < 0)
		fdata->lval = 0;
	else if (exp < 64)
		fdata->lval = fdata->mant >> (64 - exp);
	else
		fdata->lval = fdata->mant;
	if (exp < 0)
		fdata->rval = fdata->mant;
	else if (exp < 64)
		fdata->rval = fdata->mant << exp;
	else
		fdata->rval = 0;
}

int			longb_cmpn(t_longb *a, t_longb *b, int n)
{
	int			count;
	t_ulong		vala;
	t_ulong		valb;

	count = 0;
	while (n >= 9)
	{
		if (a->val[count] != b->val[count])
			return (1);
		n -= 9;
		count++;
	}
	vala = a->val[count];
	valb = b->val[count];
	while (n)
	{
		if (vala % 10 != valb % 10)
			return (1);
		vala /= 10;
		valb /= 10;
		n--;
	}
	return (0);
}

static int	calc_dpre_len(t_print *print, t_fpoint *fdata)
{
	int		pre_len;

	pre_len = 0;
	if (fdata->is_neg || (print->flags & FLAG_SPACE) ||
		(print->flags & FLAG_PLUS))
		pre_len = 1;
	return (pre_len);
}

static int	check_nan(t_print *print, t_fpoint *val)
{
	int		writed;
	int		small;

	writed = 0;
	if (val->exp == 16385)
	{
		small = print->type == 'f';
		print->type = 's';
		print->flags &= ~FLAG_NULL;
		if (val->mant & MANT_NAN)
			writed += add_c_with_flag(print, small ? "nan" : "NAN", 3);
		else if (val->is_neg && val->mant & MANT_INF)
			writed += add_c_with_flag(print, small ? "-inf" : "-INF", 4);
		else
			writed += add_c_with_flag(print, small ? "inf" : "INF", 3);
	}
	return (writed);
}

int			parse_double(t_print *print, va_list *ptr)
{
	int				writed;
	t_fpoint		val;
	t_longb			lval;
	t_longb			rval;

	print->point_len = print->is_precision ? print->precision : 6;
	if (print->point_len || print->flags & FLAG_HASH)
		print->point_len++;
	get_double_val(print, ptr, &val);
	if ((writed = check_nan(print, &val)))
		return (writed);
	round_double(print, &val, &lval, &rval);
	print->is_neg = val.is_neg;
	print->str_len = get_longb_len(&lval);
	print->pre_len = calc_dpre_len(print, &val);
	print->str_len += print->point_len;
	writed += add_pre_paddings(print);
	writed += add_double(print, &lval, &rval);
	writed += add_post_paddings(print);
	return (writed);
}
