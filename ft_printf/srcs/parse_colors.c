/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 11:51:55 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/03 11:51:55 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

static int	get_color_by_name(const char *str, char **res)
{
	int		ret;

	if (pf_strncmp(str, "{black}", (ret = 7)) == 0)
		*res = ANSI_BLACK;
	else if (pf_strncmp(str, "{red}", (ret = 5)) == 0)
		*res = ANSI_RED;
	else if (pf_strncmp(str, "{green}", (ret = 7)) == 0)
		*res = ANSI_GREEN;
	else if (pf_strncmp(str, "{yellow}", (ret = 8)) == 0)
		*res = ANSI_YELLOW;
	else if (pf_strncmp(str, "{blue}", (ret = 6)) == 0)
		*res = ANSI_BLUE;
	else if (pf_strncmp(str, "{purple}", (ret = 8)) == 0)
		*res = ANSI_PURPLE;
	else if (pf_strncmp(str, "{cyan}", (ret = 6)) == 0)
		*res = ANSI_CYAN;
	else if (pf_strncmp(str, "{white}", (ret = 7)) == 0)
		*res = ANSI_WHITE;
	else if (pf_strncmp(str, "{eoc}", (ret = 5)) == 0)
		*res = ANSI_RESET;
	else
		return (0);
	return (ret);
}

int			parse_colors(t_print *print, const char **format)
{
	char	*res;
	int		wlen;
	int		rlen;

	wlen = 0;
	if ((rlen = get_color_by_name(*format, &res)) != 0)
	{
		while (*res)
			wlen += add_to_out(print, *res++);
	}
	else
	{
		rlen = 1;
		wlen += add_to_out(print, **format);
	}
	*format = *format + rlen;
	return (wlen);
}
