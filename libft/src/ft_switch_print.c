/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:32:24 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_restart_flags(void)
{
	g_pfstr.type_conv = 'q';
	g_pfstr.spaces = 0;
	g_pfstr.precision = -1;
	g_pfstr.g = 0;
	g_pfstr.tmp_flag = 0;
	g_pfstr.n_value = 0;
	g_pfstr.sizeof_num = 0;
	g_pfstr.arr_num[0] = '\0';
	g_pfstr.prec_value = 0;
	ft_strcpy(g_pfstr.hesh, "0x");
	ft_strcpy(g_pfstr.type_flag, "qqqq");
	ft_strcpy(g_pfstr.type_mod, "00");
}

void		ft_print_prc(void)
{
	if (g_pfstr.spaces > 0 && !ft_check_is_flag('-'))
	{
		if (!ft_check_is_flag('0'))
			while (g_pfstr.spaces-- > 1)
				ft_print_c(' ');
		if (ft_check_is_flag('0'))
			while (g_pfstr.spaces-- > 1)
				ft_print_c('0');
	}
	if (g_pfstr.spaces > 0 && ft_check_is_flag('-'))
	{
		ft_print_c('%');
		while (g_pfstr.spaces-- > 1)
			ft_print_c(' ');
		return ;
	}
	ft_print_c('%');
}

int			ft_wildcards(va_list args)
{
	int		tmp;

	tmp = 0;
	if (g_pfstr.type_flag[0] == '*')
	{
		if (g_pfstr.spaces != 0)
			return (tmp = va_arg(args, int));
		g_pfstr.spaces = va_arg(args, int);
	}
	if (g_pfstr.type_flag[3] == '*')
	{
		if (g_pfstr.precision != -1)
			return (tmp = va_arg(args, int));
		g_pfstr.precision = va_arg(args, int);
	}
	if (g_pfstr.spaces < 0)
	{
		g_pfstr.spaces *= (-1);
		g_pfstr.type_flag[1] = '-';
	}
	return (tmp);
}

void		ft_switch_print(va_list args)
{
	if (ft_check_is_flag('*'))
		ft_wildcards(args);
	if (g_pfstr.type_conv == 'c' || g_pfstr.type_conv == 'C')
		ft_print_char(va_arg(args, int));
	else if (g_pfstr.type_conv == 's')
		ft_print_str(va_arg(args, char *));
	else if (g_pfstr.type_conv == 'd' || g_pfstr.type_conv == 'i')
		ft_print_d(va_arg(args, long int));
	else if (g_pfstr.type_conv == 'o' || g_pfstr.type_conv == 'u')
		ft_print_ou(va_arg(args, unsigned long long));
	else if (g_pfstr.type_conv == 'x' || g_pfstr.type_conv == 'X'
	|| g_pfstr.type_conv == 'p')
		ft_print_xxp(va_arg(args, long long int));
	else if (g_pfstr.type_conv == 'f')
		if (g_pfstr.type_mod[0] == 'L')
			ft_print_float(va_arg(args, long double));
		else
			ft_print_float(va_arg(args, double));
	else if (g_pfstr.type_conv == 'Z')
		ft_print_c('Z');
	else if (g_pfstr.type_conv == '%')
		ft_print_prc();
	ft_restart_flags();
}
