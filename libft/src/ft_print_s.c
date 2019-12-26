/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:47:57 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_c(char c)
{
	g_pfstr.num_elen++;
	write(1, &c, 1);
}

void	ft_print_s(char *s, int precision)
{
	int i;

	i = 0;
	if (g_pfstr.n_value == 1)
	{
		g_pfstr.n_value = 2;
		if (g_pfstr.type_conv == 'x' || g_pfstr.type_conv == 'X' ||
		g_pfstr.type_conv == 'p')
			ft_print_s(g_pfstr.hesh, -1);
		else
			ft_print_c('-');
		ft_del_flag('-');
	}
	while (s[i] != '\0' && precision--)
	{
		ft_print_c(s[i]);
		i++;
	}
}

void	ft_print_char(int chr)
{
	char tmp[2];

	tmp[0] = chr;
	tmp[1] = '\0';
	g_pfstr.spaces--;
	if (chr == 0)
	{
		if (!ft_check_is_flag('-'))
		{
			while (g_pfstr.spaces-- > 0)
				ft_print_c(' ');
			return (ft_print_c(0));
		}
		if (ft_check_is_flag('-'))
			ft_print_c(0);
	}
	g_pfstr.precision = -1;
	ft_display_string(tmp);
}

void	ft_print_spc_str(void)
{
	while (g_pfstr.spaces-- > 0)
	{
		if (!ft_check_is_flag('0'))
			ft_print_c(' ');
		else
		{
			if (ft_check_is_flag('-'))
				ft_print_c(' ');
			else
				ft_print_c('0');
		}
	}
}

void	ft_print_str(char *str)
{
	char *str2;

	g_pfstr.sizeof_num = -1;
	if (str == NULL)
		str2 = ft_strjoin("(null)", "");
	else
		str2 = ft_strjoin(str, "");
	g_pfstr.sizeof_num = ft_strlen(str2);
	if (g_pfstr.precision == 0)
		return (ft_display_string(""));
	if (g_pfstr.precision > 0)
	{
		str2[g_pfstr.precision] = '\0';
		g_pfstr.sizeof_num = ft_strlen(str2);
		if (g_pfstr.sizeof_num)
			g_pfstr.spaces -= g_pfstr.precision;
		if (g_pfstr.precision > g_pfstr.sizeof_num && g_pfstr.sizeof_num)
			g_pfstr.spaces += (g_pfstr.precision - g_pfstr.sizeof_num);
	}
	else
		g_pfstr.spaces -= g_pfstr.sizeof_num;
	g_pfstr.sizeof_num = 0;
	g_pfstr.precision = -1;
	ft_display_string(str2);
	free(str2);
}
