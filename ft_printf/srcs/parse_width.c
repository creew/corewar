/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:48:04 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_width(t_print *print, const char *format, va_list *ptr)
{
	int			count;
	int			f;

	count = 0;
	f = 1;
	while (format[count] == '*' || pf_isdigit(format[count]))
	{
		if (format[count] == '*' && (f = 1))
		{
			if ((print->width = va_arg(*ptr, int)) < 0)
			{
				print->width = -print->width;
				print->flags |= FLAG_MINUS;
			}
		}
		else
		{
			if (f && !(f = 0))
				print->width = 0;
			print->width *= 10;
			print->width += (format[count] - '0');
		}
		count++;
	}
	return (count);
}
