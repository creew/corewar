/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:50:30 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		clear_tprint(t_print *print)
{
	print->type = 0;
	print->is_precision = 0;
	print->flags = 0;
	print->width = 0;
	print->precision = 0;
	print->lenmod = 0;
	print->pre_len = 0;
	print->pad_len = 0;
	print->str_len = 0;
	print->point_len = 0;
	print->is_val = 0;
	print->is_neg = 0;
	print->max_rlen = 0;
}

static int		parse_str(t_print *print, const char *format, va_list *ptr)
{
	size_t	count;

	count = 0;
	count += parse_flags(print, format + count);
	count += parse_width(print, format + count, ptr);
	count += parse_precision(print, format + count, ptr);
	count += parse_lenmod(print, format + count);
	count += parse_type(print, format + count);
	return (count);
}

int				ft_allprintf(const char *format, va_list *ptr,
								void (f)(void **, char *, size_t), void *param)
{
	t_print		print;
	int			out;

	out = 0;
	pf_bzero(&print, sizeof(t_print));
	print.write_func = f;
	print.write_param = param;
	while (*format)
	{
		if (*format == '%')
		{
			clear_tprint(&print);
			format++;
			format += parse_str(&print, format, ptr);
			out += parse_format(&print, ptr);
		}
		else if (*format == '{')
			out += parse_colors(&print, &format);
		else
			out += add_to_out(&print, *format++);
	}
	flush_buf(&print);
	return (out);
}
