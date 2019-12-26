/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qq_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:29:34 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_sign(char chr)
{
	if (chr == '-')
	{
		g_pfstr.n_value = 2;
		if (g_pfstr.type_conv == 'x' || g_pfstr.type_conv == 'X'
		|| g_pfstr.type_conv == 'p')
			ft_print_s(g_pfstr.hesh, -1);
		else
			ft_print_c('-');
		ft_del_flag('-');
	}
	if (ft_check_is_flag(chr))
	{
		ft_del_flag(chr);
		ft_print_c(chr);
	}
}

void	ft_display_string_minus(char *str)
{
	if (ft_check_is_flag(' ') && !ft_check_is_flag('+')
		&& g_pfstr.n_value == 0)
		ft_print_sign(' ');
	if (ft_check_is_flag('+') && g_pfstr.n_value == 0)
		ft_print_sign('+');
	if (g_pfstr.precision < 1 && g_pfstr.precision != 0)
		ft_print_s(str, -1);
	else
	{
		if (g_pfstr.n_value)
			ft_print_sign('-');
		while (g_pfstr.precision-- > 0)
			ft_print_c('0');
		ft_print_s(str, -1);
	}
	ft_print_spc_d(' ');
}

void	ft_dsp_str_minus_false_add(char *str)
{
	if (ft_check_is_flag('+') && g_pfstr.precision != 0
		&& g_pfstr.n_value == 0)
		ft_print_sign('+');
	if (g_pfstr.precision < 1)
		ft_print_s(str, -1);
	if (g_pfstr.precision > 0)
	{
		if (g_pfstr.n_value == 1)
			ft_print_sign('-');
		if (ft_check_is_flag('+') && g_pfstr.n_value == 0)
			ft_print_sign('+');
		while (g_pfstr.precision-- > 0)
			ft_print_c('0');
		ft_print_s(str, -1);
	}
}

void	ft_dsp_str_minus_false(char *str)
{
	if (ft_check_is_flag(' ') && !ft_check_is_flag('+')
		&& !g_pfstr.n_value)
		ft_print_sign(' ');
	if (g_pfstr.precision > 0 && g_pfstr.spaces > 0)
		ft_print_spc_d(' ');
	if (g_pfstr.precision == 0 && ft_check_is_flag('+')
		&& g_pfstr.n_value == 0)
	{
		ft_print_sign('+');
		g_pfstr.spaces--;
		return (ft_print_s(str, -1));
	}
	if (ft_check_is_flag('0') && !g_pfstr.prec_value)
	{
		if (g_pfstr.n_value)
			ft_print_sign('-');
		if (ft_check_is_flag('+'))
			ft_print_sign('+');
		ft_print_spc_d('0');
	}
	ft_print_spc_d(' ');
	ft_dsp_str_minus_false_add(str);
}

void	ft_display_string(char *str)
{
	ft_check_is_flag('-') == 1 ?
	ft_display_string_minus(str) : ft_dsp_str_minus_false(str);
}
