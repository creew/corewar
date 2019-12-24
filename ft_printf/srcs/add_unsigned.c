/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:05 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_unsigned_length(t_ullong val, size_t base, t_ullong *powout)
{
	int		length;

	if (powout)
		*powout = 1;
	length = 1;
	if (!val)
		return (1);
	while ((val /= base))
	{
		length++;
		if (powout)
			*powout = *powout * base;
	}
	return (length);
}

int		get_char_base(t_print *print, int val)
{
	if (val < 10)
		return (val + '0');
	if (print->type == 'x' || print->type == 'p')
		return (val - 10 + 'a');
	if (print->type == 'X')
		return (val - 10 + 'A');
	return ('$');
}

int		add_unsigned_base(t_print *print, t_ullong val, size_t base)
{
	int			writed;
	t_ullong	pow;
	int			len;
	int			count;

	count = -1;
	writed = 0;
	len = get_unsigned_length(val, base, &pow);
	while (++count < (print->precision - len))
		writed += add_to_out(print, '0');
	while (--len > 0)
	{
		writed += add_to_out(print, get_char_base(print, (val / pow) % base));
		pow /= base;
	}
	writed += add_to_out(print, get_char_base(print, val % base));
	return (writed);
}
