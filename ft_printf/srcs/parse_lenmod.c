/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lenmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:12:58 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_lenmod(t_print *print, const char *format)
{
	size_t	count;

	count = 0;
	if (format[0] && pf_strchr(LENMOD_STR, format[0]))
	{
		count++;
		if (*format == 'h' && format[1] == 'h' && ++count)
			print->lenmod = LENMOD_HH;
		else if (*format == 'h')
			print->lenmod = LENMOD_H;
		else if (*format == 'l' && format[1] == 'l' && ++count)
			print->lenmod = LENMOD_LL;
		else if (*format == 'l')
			print->lenmod = LENMOD_L;
		else if (*format == 'j')
			print->lenmod = LENMOD_J;
		else if (*format == 't')
			print->lenmod = LENMOD_T;
		else if (*format == 'z')
			print->lenmod = LENMOD_Z;
		else if (*format == 'L')
			print->lenmod = LENMOD_BL;
	}
	return (count);
}
