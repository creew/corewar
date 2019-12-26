/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xXp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:32:24 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_convert_xxp(unsigned long int *num)
{
	if (g_pfstr.type_mod[0] == '0' && g_pfstr.type_conv == 'p')
		*num = (unsigned long int)*num;
	if (g_pfstr.type_mod[0] == '0' && g_pfstr.type_conv != 'p')
		*num = (unsigned int)*num;
	if (g_pfstr.type_mod[0] == 'h')
		*num = (unsigned short)*num;
	if (g_pfstr.type_mod[0] == 'h' && g_pfstr.type_mod[1] == 'h')
		*num = (unsigned char)*num;
}

void	ft_xxp_zero(void)
{
	if (g_pfstr.type_conv == 'p')
	{
		if (g_pfstr.precision == 0)
			return (ft_display_string(g_pfstr.hesh));
		else if (g_pfstr.precision < 0)
		{
			g_pfstr.spaces -= 3;
			return (ft_display_string("0x0"));
		}
		else if (g_pfstr.precision > 0)
		{
			g_pfstr.spaces -= (2 + g_pfstr.precision);
			g_pfstr.precision--;
			while (g_pfstr.spaces-- > 0)
				ft_print_c(' ');
			ft_print_s("0x", -1);
			while (g_pfstr.precision-- > 0)
				ft_print_c('0');
		}
	}
	return (ft_simple_zero());
}

void	ft_print_hesh_xxp(void)
{
	if (g_pfstr.type_conv == 'X')
		g_pfstr.hesh[1] = 'X';
	g_pfstr.n_value = 1;
	g_pfstr.spaces -= 2;
	ft_del_flag('#');
	ft_display_string(g_pfstr.arr_num);
}

void	ft_print_xxp(unsigned long int num)
{
	ft_type_convert_xxp(&num);
	if (g_pfstr.precision == 0)
	{
		ft_del_flag(' ');
		ft_del_flag('0');
	}
	if (num == 0)
		return (ft_xxp_zero());
	ft_itoa_base(num, 16);
	ft_del_flag('+');
	ft_del_flag(' ');
	ft_prep_conv();
	if (g_pfstr.type_conv == 'p' || ft_check_is_flag('#'))
		return (ft_print_hesh_xxp());
	ft_display_string(g_pfstr.arr_num);
}
