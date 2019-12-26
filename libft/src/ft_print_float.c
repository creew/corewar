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

void					ft_flags_float(void)
{
	if (g_pfstr.n_value)
	{
		ft_print_c('-');
		g_pfstr.n_value = 0;
		ft_del_flag('+');
	}
	if (ft_check_is_flag('+'))
	{
		ft_print_sign('+');
		g_pfstr.spaces--;
		ft_del_flag(' ');
	}
	if (ft_check_is_flag(' '))
	{
		ft_print_c(' ');
		g_pfstr.spaces--;
		ft_del_flag(' ');
	}
}

void					ft_spc_float(unsigned long long l_var, long double num)
{
	if (!ft_check_is_flag('-'))
	{
		if (!g_pfstr.n_value && (ft_check_is_flag('+')
		|| ft_check_is_flag(' ')) && !ft_check_is_flag('0'))
			g_pfstr.spaces--;
		if (ft_check_is_flag('0'))
			ft_flags_float();
		while (g_pfstr.spaces-- > 0)
			ft_print_c(ft_check_is_flag('0') == 1 ? '0' : ' ');
		ft_flags_float();
	}
	ft_flags_float();
	if (l_var > 0)
		ft_print_num_float(l_var);
	else
		ft_print_c('0');
	ft_print_c('.');
	ft_print_float_right(num);
	if (ft_check_is_flag('-'))
	{
		while (g_pfstr.spaces-- > 0)
			ft_print_c(' ');
	}
}

void					ft_check_sign_float(long double *num)
{
	t_float_union			d1;

	d1.pf_union = *num;
	if (d1.float_parts.sign == 1)
	{
		g_pfstr.n_value = 1;
		ft_del_flag(' ');
		ft_del_flag('+');
	}
}

void					ft_print_float_add(long double num,
		unsigned long long l_var)
{
	char				*tmp;

	ft_prep_conv();
	if (!ft_check_is_flag('#'))
	{
		g_pfstr.precision = -1;
		return (ft_display_string(num >= 1
		? g_pfstr.arr_num : "0"));
	}
	if (ft_check_is_flag('#'))
	{
		g_pfstr.spaces--;
		if (l_var == 0)
			tmp = ft_strjoin(g_pfstr.arr_num, "0.");
		else
			tmp = ft_strjoin(g_pfstr.arr_num, ".");
		ft_display_string(tmp);
		free(tmp);
		return ;
	}
}

void					ft_print_float(long double num)
{
	unsigned long long	l_var;
	long double			tmp_num;

	tmp_num = num;
	ft_exception_float(&num, &tmp_num);
	tmp_num = ft_prec_dbl_round(tmp_num, 5.0L);
	l_var = (unsigned long long)tmp_num;
	ft_itoa_base(l_var, 10);
	if (g_pfstr.precision == 0)
		return (ft_print_float_add(num, l_var));
	if (g_pfstr.precision == -1)
		g_pfstr.precision = 6;
	g_pfstr.spaces -= (g_pfstr.sizeof_num + 1 + g_pfstr.precision);
	if (g_pfstr.spaces > 0)
		return (ft_spc_float(l_var, num));
	ft_flags_float();
	if (l_var > 0)
		ft_print_num_float(l_var);
	else
		ft_print_c('0');
	ft_print_c('.');
	ft_print_float_right(num);
}
