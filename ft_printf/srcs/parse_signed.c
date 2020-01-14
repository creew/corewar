/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:30:49 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_llong			get_llong_val(t_print *print, va_list *ptr)
{
	t_llong val;

	if (print->lenmod == LENMOD_HH)
		val = (char)va_arg(*ptr, int);
	else if (print->lenmod == LENMOD_H)
		val = (short)va_arg(*ptr, int);
	else if (print->lenmod == LENMOD_L || print->lenmod == LENMOD_J)
		val = va_arg(*ptr, long);
	else if (print->lenmod == LENMOD_LL)
		val = va_arg(*ptr, long long);
	else if (print->lenmod == LENMOD_Z)
		val = va_arg(*ptr, size_t);
	else
		val = (int)va_arg(*ptr, int);
	return (val);
}

int				parse_signed_base(t_print *print, va_list *ptr, int base)
{
	t_llong		val1;
	int			writed;
	t_ullong	val;

	writed = 0;
	val1 = get_llong_val(print, ptr);
	if (print->lenmod == LENMOD_Z)
	{
		return (add_pad_and_uval(print, (t_ullong)val1, base));
	}
	if (val1 < 0)
		print->is_neg = 1;
	val = val1 < 0 ? (t_ullong)(-val1) : (t_ullong)val1;
	if (val)
		print->is_val = 1;
	print->str_len = get_unsigned_length(val, base, NULL);
	print->pre_len = calc_digit_pre_len(print);
	add_precision(print);
	writed += add_pre_paddings(print);
	if (print->str_len)
		writed += add_unsigned_base(print, val, base);
	writed += add_post_paddings(print);
	return (writed);
}
