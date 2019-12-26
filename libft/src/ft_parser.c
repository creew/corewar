/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:15:39 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_spaces(void)
{
	if (ft_isdigit(g_pfstr.format[g_pfstr.i]))
	{
		g_pfstr.spaces = ft_atoi(&g_pfstr.format[g_pfstr.i]);
		while (ft_isdigit(g_pfstr.format[g_pfstr.i]))
			g_pfstr.i++;
	}
}

void	ft_precision(void)
{
	if (g_pfstr.format[g_pfstr.i] == '.')
	{
		if (g_pfstr.format[g_pfstr.i + 1] == '*')
		{
			g_pfstr.type_flag[3] = '*';
			return ;
		}
		g_pfstr.precision = 0;
		if (ft_isdigit(g_pfstr.format[g_pfstr.i + 1]))
			g_pfstr.precision = ft_atoi(&g_pfstr.format[g_pfstr.i + 1]);
		g_pfstr.i++;
		while (ft_isdigit(g_pfstr.format[g_pfstr.i]))
			g_pfstr.i++;
	}
}

void	ft_check_modiv(void)
{
	int	i;

	i = 0;
	while (g_pfstr.mod_mask[i] != 0)
	{
		if (g_pfstr.format[g_pfstr.i] == g_pfstr.mod_mask[i])
		{
			g_pfstr.type_mod[0] = g_pfstr.mod_mask[i];
			g_pfstr.i++;
			if (g_pfstr.format[g_pfstr.i] == g_pfstr.mod_mask[i])
			{
				g_pfstr.type_mod[1] = g_pfstr.mod_mask[i];
				g_pfstr.i++;
			}
		}
		i++;
	}
}

void	ft_parser(va_list args)
{
	g_pfstr.i++;
	if (g_pfstr.format[g_pfstr.i] == '\0')
		return ;
	if (g_pfstr.format[g_pfstr.i] == '%')
		return (ft_print_prc());
	ft_check_begin_flags(0, 0);
	ft_spaces();
	ft_precision();
	ft_check_modiv();
	while (!ft_conv_mask(g_pfstr.format[g_pfstr.i])
	&& g_pfstr.format[g_pfstr.i] != '\0')
		g_pfstr.i++;
	ft_switch_print(args);
}
