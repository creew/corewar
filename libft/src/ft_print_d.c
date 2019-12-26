/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:07:22 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_type_convert_d(long long *num)
{
	if (g_pfstr.type_mod[0] == '0')
		*num = (int)*num;
	if (g_pfstr.type_mod[0] == 'h')
		*num = (short)*num;
	if (g_pfstr.type_mod[0] == 'h' && g_pfstr.type_mod[1] == 'h')
		*num = (char)*num;
}

void		ft_del_flag(char c)
{
	size_t	i;

	i = 0;
	while (g_pfstr.type_flag[i] != '\0')
	{
		if (g_pfstr.type_flag[i] == c)
		{
			g_pfstr.type_flag[i] = 'q';
			return ;
		}
		i++;
	}
}

void		ft_simple_zero(void)
{
	char	tmp[INT8_MAX];
	int		i;

	i = -1;
	while (i++ < INT8_MAX)
		tmp[i] = 0;
	if (g_pfstr.precision == 0)
	{
		if (g_pfstr.spaces > 0)
			ft_del_flag(' ');
		ft_del_flag('0');
		if (ft_check_is_flag('+'))
		{
			ft_del_flag(' ');
			g_pfstr.spaces--;
			ft_del_flag('+');
			return (ft_display_string("+"));
		}
		return (ft_display_string(""));
	}
	ft_simple_zero_add(tmp);
}

void		ft_prep_conv(void)
{
	if (g_pfstr.precision <= g_pfstr.sizeof_num && g_pfstr.precision >= 0)
		ft_del_flag('0');
	g_pfstr.spaces -= g_pfstr.sizeof_num;
	g_pfstr.precision -= g_pfstr.sizeof_num;
	if (g_pfstr.precision > 0)
		g_pfstr.spaces -= g_pfstr.precision;
	if (ft_check_is_flag('+') || ft_check_is_flag(' '))
		g_pfstr.spaces--;
}

void		ft_print_d(long long num)
{
	ft_type_convert_d(&num);
	if (num == 0)
		ft_simple_zero();
	if (num < 0)
	{
		g_pfstr.n_value = 1;
		ft_itoa_base(num * (-1), 10);
		ft_del_flag('+');
		if (g_pfstr.precision <= g_pfstr.sizeof_num
		&& g_pfstr.precision >= 0)
			ft_del_flag('0');
		g_pfstr.spaces -= g_pfstr.sizeof_num;
		g_pfstr.precision -= (g_pfstr.sizeof_num - 1);
		if (g_pfstr.precision > 0)
			g_pfstr.spaces -= g_pfstr.precision;
		ft_display_string(g_pfstr.arr_num);
		return ;
	}
	ft_itoa_base(num, 10);
	ft_prep_conv();
	if (g_pfstr.spaces > 0 && g_pfstr.precision == 0)
		ft_del_flag(' ');
	ft_display_string(g_pfstr.arr_num);
	return ;
}
