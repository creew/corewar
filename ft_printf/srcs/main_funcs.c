/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:43:27 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/28 20:43:27 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ptr;
	int			out;

	va_start(ptr, format);
	out = ft_allprintf(format, &ptr, fp_write_c, 0);
	va_end(ptr);
	return (out);
}

int				ft_sprintf(char *s, const char *format, ...)
{
	va_list		ptr;
	int			out;

	*s = '\0';
	va_start(ptr, format);
	out = ft_allprintf(format, &ptr, s_write_c, s);
	va_end(ptr);
	return (out);
}

int				ft_snprintf(char *s, size_t size, const char *format, ...)
{
	va_list		ptr;
	int			out;
	t_snparam	param;

	out = 0;
	if (size > 0)
	{
		*s = '\0';
		va_start(ptr, format);
		param.s = s;
		param.size = size - 1;
		out = ft_allprintf(format, &ptr, sn_write_c, &param);
		va_end(ptr);
	}
	return (out);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		ptr;
	int			out;

	va_start(ptr, format);
	out = ft_allprintf(format, &ptr, fp_write_fd, &fd);
	va_end(ptr);
	return (out);
}
