/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:15:39 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_conv_mask(char s)
{
	int	i;

	i = 0;
	while (g_pfstr.conv_mask[i] != '\0')
	{
		if (s == g_pfstr.conv_mask[i])
		{
			g_pfstr.type_conv = g_pfstr.conv_mask[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_check_is_flag(char c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_pfstr.type_flag[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_begin_flags(int x, int j)
{
	int	i;

	i = -1;
	while (j < 14)
	{
		while (g_pfstr.flag_mask[++i] != '\0')
		{
			if (g_pfstr.format[g_pfstr.i] == g_pfstr.flag_mask[i])
			{
				g_pfstr.type_flag[x] = g_pfstr.flag_mask[i];
				x++;
				g_pfstr.i++;
				break ;
			}
		}
		i = -1;
		j++;
	}
}
