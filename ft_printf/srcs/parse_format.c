/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:41:00 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_format(t_print *print, va_list *ptr)
{
	char	type;
	int		out;

	out = 0;
	type = print->type;
	if (type == 'c')
		out += parse_character(type, print, ptr);
	else if (type == 's')
		out += parse_string(type, print, ptr);
	else if (type == 'p' || type == 'x' || type == 'X')
		out += parse_unsigned_base(print, ptr, 16);
	else if (type == 'u')
		out += parse_unsigned_base(print, ptr, 10);
	else if (type == 'o')
		out += parse_unsigned_base(print, ptr, 8);
	else if (type == 'b' || type == 'B')
		out += parse_unsigned_base(print, ptr, 2);
	else if (type == 'd' || type == 'i')
		out += parse_signed_base(print, ptr, 10);
	else if (type == 'f' || type == 'F')
		out += parse_double(print, ptr);
	else if (type)
		out += add_c_with_flag(print, &type, 1);
	return (out);
}
