/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:23:40 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_writed(t_print *print, char c, int *writed, int *len)
{
	if (len)
	{
		if (*len)
		{
			*writed += add_to_out(print, c);
			*len = *len - 1;
		}
		else
			return (0);
	}
	else
		*writed += add_to_out(print, c);
	return (1);
}

static t_ullong	reduce_val(t_ullong val, size_t *base)
{
	t_ullong	new_val;

	new_val = val % *base;
	*base = *base / 10;
	return (new_val);
}

int				print_longb(t_print *print, t_longb *longb, int *len)
{
	int			count;
	size_t		base;
	t_ullong	val;
	int			writed;

	writed = 0;
	count = longb->size;
	while (count-- && (!len || *len))
	{
		val = longb->val[count];
		base = longb->base / 10;
		while (count == longb->size - 1 && base >= 10 && val / base == 0)
			val = reduce_val(val, &base);
		while (base >= 10)
		{
			check_writed(print, val / base + '0', &writed, len);
			val = reduce_val(val, &base);
		}
		check_writed(print, val + '0', &writed, len);
	}
	if (!longb->size)
		check_writed(print, '0', &writed, len);
	return (writed);
}

int				round_double(t_print *print, t_fpoint *fdata,
						t_longb *lval, t_longb *rval)
{
	t_longb		round;
	int			order;
	int			point_len;

	if ((point_len = print->point_len))
		point_len--;
	calc_lval(fdata, lval);
	calc_rval(fdata, rval);
	init_max_val(&round);
	print->max_rlen = get_longb_len(&round);
	order = -1;
	while (++order < point_len)
		div_longb_uint(&round, 10);
	if (print->max_rlen >= order &&
		!longb_cmpn(rval, &round, print->max_rlen - order))
	{
		if (print->point_len &&
			(!(get_val_by_pos(rval, print->max_rlen - order) & 1)))
			return (0);
		if (!print->point_len && (!(get_val_by_pos(lval, 0) & 1)))
			return (0);
	}
	if (!add_longb(rval, &round))
		add_longb_uint(lval, 1);
	return (0);
}

int				add_double(t_print *print, t_longb *lval, t_longb *rval)
{
	int			writed;
	int			r_len;
	int			lpoint;

	writed = print_longb(print, lval, NULL);
	if (print->point_len)
	{
		writed += add_to_out(print, '.');
		lpoint = print->point_len - 1;
		r_len = get_longb_len(rval);
		while (r_len++ < print->max_rlen && lpoint-- > 0)
			writed += add_to_out(print, '0');
		if (lpoint > 0)
		{
			writed += print_longb(print, rval, &lpoint);
			while (lpoint--)
				writed += add_to_out(print, '0');
		}
	}
	return (writed);
}
