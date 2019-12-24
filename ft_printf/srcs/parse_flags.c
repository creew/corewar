/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:12:18 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_flag(char c)
{
	if (c && pf_strchr(FLAGS_STR, c))
		return (1);
	return (0);
}

int				parse_flags(t_print *print, const char *format)
{
	int		count;
	char	c;

	count = 0;
	while (is_flag((c = format[count])))
	{
		if (c == '+')
			print->flags |= FLAG_PLUS;
		else if (c == '-')
			print->flags |= FLAG_MINUS;
		else if (c == ' ')
			print->flags |= FLAG_SPACE;
		else if (c == '#')
			print->flags |= FLAG_HASH;
		else if (c == '0')
			print->flags |= FLAG_NULL;
		else if (c == '\'')
			print->flags |= FLAG_APOSTROFE;
		count++;
	}
	if (print->flags & FLAG_PLUS)
		print->flags &= ~FLAG_SPACE;
	if (print->flags & FLAG_MINUS)
		print->flags &= ~FLAG_NULL;
	return (count);
}
