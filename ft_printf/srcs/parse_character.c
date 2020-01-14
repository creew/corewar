/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:53:18 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_wc_len(wchar_t c)
{
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

static size_t	ft_wcslen(wchar_t *ws, int size)
{
	size_t	len;

	len = 0;
	while (size-- > 0)
		len += get_wc_len(*ws++);
	return (len);
}

int				add_wc_with_flag(t_print *print, wchar_t *wc, int len)
{
	int	count;
	int writed;

	print->str_len = ft_wcslen(wc, len);
	writed = add_pre_paddings(print);
	count = -1;
	while (++count < len)
		writed += addw_to_out(print, *wc++);
	writed += add_post_paddings(print);
	return (writed);
}

int				add_c_with_flag(t_print *print, char *c, int len)
{
	int	count;
	int writed;

	print->str_len = len;
	writed = add_pre_paddings(print);
	count = -1;
	while (++count < len)
		writed += add_to_out(print, *c++);
	writed += add_post_paddings(print);
	return (writed);
}

int				parse_character(char type, t_print *print, va_list *ptr)
{
	wchar_t			wch[2];
	unsigned char	val[2];
	int				count;

	count = 0;
	if (type == 'c' && print->lenmod != LENMOD_L)
	{
		val[1] = '\0';
		val[0] = (unsigned char)va_arg(*ptr, int);
		count += add_c_with_flag(print, (char *)val, 1);
	}
	else
	{
		wch[1] = L'\0';
		wch[0] = (wchar_t)va_arg(*ptr, wint_t);
		count += add_wc_with_flag(print, wch, 1);
	}
	return (count);
}
