/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:17:51 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ullong	get_ullong_val(t_print *print, va_list *ptr)
{
	t_ullong val;

	if (print->type == 'p')
		val = (unsigned long long)va_arg(*ptr, void *);
	else if (print->lenmod == LENMOD_HH)
		val = (unsigned char)va_arg(*ptr, unsigned int);
	else if (print->lenmod == LENMOD_H)
		val = (unsigned short)va_arg(*ptr, unsigned int);
	else if (print->lenmod == LENMOD_L || print->lenmod == LENMOD_J)
		val = va_arg(*ptr, unsigned long);
	else if (print->lenmod == LENMOD_LL)
		val = va_arg(*ptr, unsigned long long);
	else if (print->lenmod == LENMOD_Z)
		val = va_arg(*ptr, size_t);
	else
		val = va_arg(*ptr, unsigned int);
	return (val);
}

int			calc_digit_pre_len(t_print *print)
{
	int		pre_len;

	pre_len = 0;
	if (print->type == 'x' || print->type == 'X' ||
		print->type == 'b' || print->type == 'B')
	{
		if (print->flags & FLAG_HASH && print->is_val)
			pre_len = 2;
	}
	if (print->type == 'p')
		pre_len = 2;
	if (print->type == 'o' && print->flags & FLAG_HASH)
	{
		if (print->str_len >= print->precision &&
			(print->is_val || print->precision > 1))
			pre_len = 1;
		if (!print->is_val && !print->precision && print->is_precision)
			pre_len = 1;
	}
	if (print->type == 'd' || print->type == 'i')
		if (print->is_neg || (print->flags & FLAG_SPACE) ||
			(print->flags & FLAG_PLUS))
			pre_len = 1;
	return (pre_len);
}

void		add_precision(t_print *print)
{
	if (print->is_precision)
	{
		if (print->precision > print->str_len ||
			(!print->is_val && print->precision == 0))
			print->str_len = print->precision;
		if (print->type != 'p')
		{
			print->flags &= ~FLAG_NULL;
		}
	}
}

int			add_pad_and_uval(t_print *print, t_ullong val, int base)
{
	int		writed;

	writed = 0;
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

int			parse_unsigned_base(t_print *print, va_list *ptr, int base)
{
	t_ullong	val;

	val = get_ullong_val(print, ptr);
	return (add_pad_and_uval(print, val, base));
}
