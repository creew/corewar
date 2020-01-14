/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:05:37 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_type(t_print *print, const char *format)
{
	char c;

	if ((c = *format))
	{
		print->type = c;
		if (pf_strchr(DEPRECATED_STR, c))
		{
			print->type = pf_tolower(c);
			print->lenmod = LENMOD_L;
		}
		return (1);
	}
	return (0);
}
