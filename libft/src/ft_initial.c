/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:45:11 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_simple_zero_add(char *tmp)
{
	if (ft_check_is_flag('+'))
		ft_del_flag(' ');
	if (ft_check_is_flag('+') || ft_check_is_flag(' '))
		g_pfstr.spaces--;
	if (g_pfstr.precision > 0)
	{
		g_pfstr.spaces -= g_pfstr.precision;
		tmp[g_pfstr.precision] = '\0';
		ft_del_flag('0');
		return (ft_display_string(tmp));
	}
	else
		g_pfstr.spaces--;
	return (ft_display_string("0"));
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_print_spc_d(char c)
{
	while (g_pfstr.spaces-- > 0)
		ft_print_c(c);
}

void	ft_initial(const char *format)
{
	g_pfstr.format = (char *)format;
	g_pfstr.num_elen = 0;
	g_pfstr.i = 0;
	g_pfstr.g = 0;
	g_pfstr.conv_mask = "CcspdiouxXf%Z";
	g_pfstr.flag_mask = "#+-0 *";
	g_pfstr.mod_mask = "hlL";
	g_pfstr.spaces = 0;
	g_pfstr.precision = -1;
	g_pfstr.type_mod[0] = '0';
	g_pfstr.tmp_flag = 0;
	g_pfstr.n_value = 0;
	g_pfstr.sizeof_num = 0;
	g_pfstr.prec_value = 0;
	ft_strcpy(g_pfstr.hesh, "0x");
	ft_strcpy(g_pfstr.type_flag, "qqqq");
}
