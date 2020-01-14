/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_paddings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:32:39 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_pre_paddings(t_print *print)
{
	int		writed;
	int		count;

	count = -1;
	writed = 0;
	if (!(print->flags & FLAG_MINUS) && !(print->flags & FLAG_NULL))
	{
		while ((++count + print->str_len + print->pre_len) < print->width)
			writed += add_to_out(print, ' ');
	}
	writed += add_prefix(print);
	if (!(print->flags & FLAG_MINUS) && (print->flags & FLAG_NULL))
	{
		while ((++count + print->str_len + print->pre_len) < print->width)
			writed += add_to_out(print, '0');
	}
	print->pad_len += writed;
	return (writed);
}

int		add_post_paddings(t_print *print)
{
	int		writed;
	int		count;

	count = print->str_len + print->pre_len;
	writed = 0;
	if (print->flags & FLAG_MINUS)
	{
		while (++count <= print->width)
			writed += add_to_out(print, ' ');
	}
	print->pad_len += writed;
	return (writed);
}
