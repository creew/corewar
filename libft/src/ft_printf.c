/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:07:15 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int			ft_check_exp(int i, int j)
{
	if (g_pfstr.format[i] == '%' && g_pfstr.format[i + 1] == '\0')
		return (1);
	if (g_pfstr.format[i++] == '%')
		while (g_pfstr.format[i])
		{
			j = 0;
			while (g_pfstr.conv_mask[j] != '\0')
			{
				if (g_pfstr.format[i] == g_pfstr.conv_mask[j])
					return (0);
				j++;
			}
			if (g_pfstr.format[i + 1] == '\0')
				return (1);
			i++;
		}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_initial(format);
	if (ft_check_exp(0, 0))
		return (0);
	while (format[g_pfstr.i] != '\0')
	{
		if (format[g_pfstr.i] == '%')
			ft_parser(args);
		else
			ft_print_c(format[g_pfstr.i]);
		g_pfstr.i++;
	}
	va_end(args);
	return (g_pfstr.num_elen);
}
