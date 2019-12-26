/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:11:13 by gdorcas           #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_nan_delete_flags(void)
{
	ft_del_flag('+');
	ft_del_flag('0');
}

int		ft_check_inf(long double *num)
{
	if (*num != *num)
	{
		ft_strcpy(g_pfstr.arr_num, "nan");
		g_pfstr.spaces -= 3;
		g_pfstr.precision = -1;
		ft_nan_delete_flags();
		return (1);
	}
	if (*num == (5.0 / 0.0))
	{
		ft_strcpy(g_pfstr.arr_num, "inf");
		g_pfstr.spaces -= 3;
		g_pfstr.precision = -1;
		ft_nan_delete_flags();
		return (1);
	}
	if (*num == ((-5.0) / 0.0))
	{
		ft_strcpy(g_pfstr.arr_num, "-inf");
		g_pfstr.spaces -= 4;
		g_pfstr.precision = -1;
		ft_nan_delete_flags();
		return (1);
	}
	return (0);
}

void	ft_exception_float(long double *num, long double *tmp_num)
{
	if (*num == 0.0)
		ft_check_sign_float(num);
	if (*num < 0.)
		ft_float_negat(num, tmp_num);
	if (ft_check_inf(num))
		return (ft_display_string(g_pfstr.arr_num));
}
