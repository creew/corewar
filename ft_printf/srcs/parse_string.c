/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:17:41 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_wc_len(wchar_t c)
{
	if (!c)
		return (0);
	if (c < 0x80)
		return (1);
	else if (c >= 0x80 && c < 0x800)
		return (2);
	else if (c >= 0x800 && c < 0x10000)
		return (3);
	else if (c >= 0x10000 && c < 0x110000)
		return (4);
	return (1);
}

static size_t	ft_wclen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	while (*ws++)
		len++;
	return (len);
}

int				parse_wstr(t_print *print, wchar_t *wstr)
{
	int			count;
	size_t		size;

	count = 0;
	size = ft_wclen(wstr);
	if (print->is_precision)
	{
		size = 0;
		print->str_len = 0;
		while (wstr[size] &&
			get_wc_len(wstr[size]) + print->str_len <= print->precision)
			print->str_len += get_wc_len(wstr[size++]);
	}
	count += add_wc_with_flag(print, wstr, size);
	return (count);
}

int				parse_cstr(t_print *print, char *str)
{
	int count;

	count = 0;
	print->str_len = pf_strlen(str);
	if (print->is_precision && print->precision < print->str_len)
		print->str_len = print->precision;
	count += add_c_with_flag(print, str, print->str_len);
	return (count);
}

int				parse_string(char type, t_print *print, va_list *ptr)
{
	wchar_t		*wstr;
	char		*cstr;

	if (type == 's' && print->lenmod != LENMOD_L)
	{
		cstr = va_arg(*ptr, char *);
		if (!cstr)
			cstr = "(null)";
		return (parse_cstr(print, cstr));
	}
	wstr = va_arg(*ptr, wchar_t *);
	if (!wstr)
		wstr = L"(null)";
	return (parse_wstr(print, wstr));
}
