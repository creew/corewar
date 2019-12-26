/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:24:54 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void					ft_print_float_right(long double num)
{
	int					i;
	long double			p_num;

	i = 6;
	p_num = 0.5;
	num -= (unsigned long long)num;
	if (g_pfstr.precision > 0)
	{
		i = g_pfstr.precision;
		while (g_pfstr.precision--)
			p_num /= 10;
		num += p_num;
	}
	else
		num += 0.0000005;
	if (g_pfstr.precision > 0)
		i = g_pfstr.precision;
	num -= (int)num;
	while (i--)
	{
		ft_print_c((int)(num * 10) + '0');
		num *= 10;
		num -= (int)num;
	}
}

void					ft_print_num_float(unsigned long long num)
{
	if (num == 0)
		return ;
	if (ft_check_is_flag('+'))
		ft_print_c('+');
	ft_print_num_float(num / 10);
	ft_print_c(num % 10 + '0');
	if (ft_check_is_flag('#') && g_pfstr.precision == 0)
		ft_print_c('.');
}

double					ft_prec_dbl_round(long double num, long double n)
{
	long double			tmp_dbl;
	unsigned long		tmp_int;
	int					prec;
	int					i;

	prec = 7;
	i = -1;
	tmp_dbl = num;
	if (g_pfstr.precision >= 0)
		prec = g_pfstr.precision + 1;
	while (++i < prec)
		tmp_dbl *= 10;
	tmp_int = (unsigned long)tmp_dbl;
	if (tmp_int % 10 >= 5)
	{
		i = -1;
		while (++i < prec)
			n /= 10;
		num += n;
	}
	return (num);
}

void					ft_float_negat(long double *num, long double *tmp_num)
{
	*num *= -1;
	*tmp_num *= -1;
	g_pfstr.n_value = 1;
	ft_del_flag('+');
	ft_del_flag(' ');
}
