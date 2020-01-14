/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:37:24 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_hex_prefix(t_print *print)
{
	int		writed;

	writed = 0;
	if (print->is_val || print->type == 'p')
	{
		if (print->type == 'p' ||
			((print->flags & FLAG_HASH) && print->type == 'x'))
		{
			writed += add_to_out(print, '0');
			writed += add_to_out(print, 'x');
		}
		else if (((print->flags & FLAG_HASH) && print->type == 'X'))
		{
			writed += add_to_out(print, '0');
			writed += add_to_out(print, 'X');
		}
	}
	return (writed);
}

static int	add_oct_prefix(t_print *print)
{
	int		writed;

	writed = 0;
	if (print->flags & FLAG_HASH && print->pre_len == 1)
		writed += add_to_out(print, '0');
	return (writed);
}

static int	add_bin_prefix(t_print *print)
{
	int		writed;

	writed = 0;
	if (print->is_val)
	{
		if ((print->flags & FLAG_HASH) && print->type == 'b')
		{
			writed += add_to_out(print, '0');
			writed += add_to_out(print, 'b');
		}
		else if ((print->flags & FLAG_HASH) && print->type == 'B')
		{
			writed += add_to_out(print, '0');
			writed += add_to_out(print, 'B');
		}
	}
	return (writed);
}

static int	add_dec_prefix(t_print *print)
{
	int		writed;

	writed = 0;
	if (print->is_neg)
		writed += add_to_out(print, '-');
	else if (print->flags & FLAG_SPACE)
		writed += add_to_out(print, ' ');
	else if (print->flags & FLAG_PLUS)
		writed += add_to_out(print, '+');
	return (writed);
}

int			add_prefix(t_print *print)
{
	int		writed;

	writed = 0;
	if (print->type == 'p' || print->type == 'x' || print->type == 'X')
		writed += add_hex_prefix(print);
	if (print->type == 'o')
		writed += add_oct_prefix(print);
	if (print->type == 'd' || print->type == 'i')
		writed += add_dec_prefix(print);
	if (print->type == 'b' || print->type == 'B')
		writed += add_bin_prefix(print);
	if (print->type == 'f' || print->type == 'F')
		writed += add_dec_prefix(print);
	print->pre_len = writed;
	return (writed);
}
