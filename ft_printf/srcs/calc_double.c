/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:24:24 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_longb_len(t_longb *longb)
{
	int			len;
	t_uint		val;

	len = 0;
	if (longb->size)
	{
		if (longb->size == 1 && longb->val[0] == 0)
			len = 1;
		else
		{
			if (longb->size != 1)
				len += ((longb->size - 1) * 9);
			val = longb->val[longb->size - 1];
			while (val)
			{
				len++;
				val /= 10;
			}
		}
	}
	return (len);
}

int		get_val_by_pos(t_longb *longb, int pos)
{
	int			count;
	t_ullong	val;

	val = 0;
	count = 0;
	if (pos >= 0)
	{
		while (pos >= 9)
		{
			pos -= 9;
			count++;
		}
		if (count < longb->size)
		{
			val = longb->val[count];
			while (pos)
			{
				val = val / 10;
				pos--;
			}
			val = val % 10;
		}
	}
	return (val);
}

int		calc_lval(t_fpoint *fdata, t_longb *lval)
{
	t_longb		help;
	long		size;

	init_longb(lval, 0);
	if (fdata->exp >= 0)
	{
		size = 0;
		init_longb(&help, 1);
		while (size < fdata->exp && size < 64)
		{
			if (fdata->lval & (1ull << size))
				add_longb(lval, &help);
			add_longb(&help, &help);
			size++;
		}
		while (size < fdata->exp)
		{
			add_longb(lval, lval);
			size++;
		}
	}
	return (get_longb_len(lval));
}

int		init_max_val(t_longb *val)
{
	int count;

	count = 0;
	init_longb(val, 0);
	val->val[val->max_size - 1] = 5 * 1000 * 1000 * 100u;
	while (count < (val->max_size - 1))
		val->val[count++] = 0;
	val->size = val->max_size;
	return (0);
}

int		calc_rval(t_fpoint *fdata, t_longb *rval)
{
	t_longb		bignum;
	long		bits;

	bits = fdata->exp > 0 ? 0 : fdata->exp;
	init_max_val(&bignum);
	init_longb(rval, 0);
	while (bits < 0)
	{
		div2_longb_uint(&bignum);
		bits++;
	}
	while (bits < 64)
	{
		if (fdata->rval & (1ull << (63 - bits)))
			add_longb(rval, &bignum);
		div2_longb_uint(&bignum);
		bits++;
	}
	return (0);
}
