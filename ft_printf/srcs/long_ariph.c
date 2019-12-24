/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_ariph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:19:22 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_longb(t_longb *longb, t_ulong val)
{
	longb->size = 0;
	longb->max_size = (sizeof(longb->val) / sizeof(longb->val[0])) - 1;
	longb->base = 1 * 1000 * 1000 * 1000;
	if (!val)
		longb->val[longb->size++] = 0;
	else
	{
		while (val)
		{
			longb->val[longb->size++] = val % longb->base;
			val /= longb->base;
		}
	}
	return (1);
}

int		add_longb(t_longb *a, t_longb *b)
{
	int			max;
	int			count;
	t_ullong	val;
	size_t		add;

	count = -1;
	add = 0;
	max = MAX(a->size, b->size);
	while (++count < max)
	{
		val = (count < a->size ? a->val[count] : (size_t)0) +
				(count < b->size ? b->val[count] : (size_t)0) + add;
		if (count >= a->size)
			a->size++;
		if (val < a->base && !(add = 0))
			a->val[count] = val;
		else if ((add = 1))
			a->val[count] = val - a->base;
	}
	if (a->size > a->max_size || (add && a->size >= a->max_size))
		return (0);
	if (add)
		a->val[a->size++] = 1;
	return (1);
}

int		add_longb_uint(t_longb *a, t_uint b)
{
	int			count;
	t_ullong	val;
	t_uint		add;

	count = -1;
	add = b;
	while (++count < a->size)
	{
		val = a->val[count] + add;
		if (val < a->base && !(add = 0))
			a->val[count] = val;
		else if ((add = 1))
			a->val[count] = val - a->base;
	}
	if (add)
		a->val[a->size++] = 1;
	if (a->size > a->max_size)
		return (0);
	return (1);
}

int		div2_longb_uint(t_longb *longb)
{
	int			counta;
	t_ullong	mod;
	t_ullong	rem;

	mod = 0;
	counta = longb->size - 1;
	while (counta >= 0)
	{
		rem = longb->val[counta] & 1;
		longb->val[counta] = (longb->val[counta] + mod * longb->base) >> 1;
		if (!longb->val[counta] && counta == longb->size - 1)
			longb->size--;
		mod = rem;
		counta--;
	}
	return (1);
}

int		div_longb_uint(t_longb *longb, t_uint a)
{
	int			counta;
	t_ullong	mod;
	t_ullong	rem;

	mod = 0;
	counta = longb->size - 1;
	while (counta >= 0)
	{
		rem = longb->val[counta] % a;
		longb->val[counta] = (longb->val[counta] + mod * longb->base) / a;
		if (!longb->val[counta] && counta == longb->size - 1)
			longb->size--;
		mod = rem;
		counta--;
	}
	return (1);
}
