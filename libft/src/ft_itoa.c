/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:26:57 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*fresh_str;

	j = 0;
	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fresh_str = (char *)malloc(sizeof(char)
			* ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (fresh_str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		fresh_str[i] = s1[i];
	while (s2[j] != '\0')
	{
		fresh_str[i] = s2[j];
		i++;
		j++;
	}
	fresh_str[i] = '\0';
	return (fresh_str);
}

void			ft_hesh_oct(void)
{
	char		*num_hesh;
	int			i;

	i = 0;
	g_pfstr.hesh[1] = '\0';
	num_hesh = ft_strjoin(g_pfstr.hesh, g_pfstr.arr_num);
	while (num_hesh[i])
	{
		g_pfstr.arr_num[i] = num_hesh[i];
		i++;
	}
	g_pfstr.arr_num[i] = '\0';
	g_pfstr.sizeof_num = i;
}

unsigned long	ft_count_int(unsigned long long n, int base)
{
	int			i;

	i = 0;
	while (n)
	{
		n = n / base;
		i++;
		ft_count_int(n, base);
	}
	g_pfstr.sizeof_num = i;
	if (g_pfstr.n_value)
		g_pfstr.sizeof_num++;
	return (i);
}

void			ft_itoa_base(unsigned long long n, int base)
{
	int			i;
	char		mask_x[17];
	char		mask_xx[17];

	ft_strcpy(mask_x, "0123456789abcdef");
	ft_strcpy(mask_xx, "0123456789ABCDEF");
	i = ft_count_int(n, base);
	g_pfstr.arr_num[i] = '\0';
	i--;
	while (n)
	{
		if (g_pfstr.type_conv == 'X')
			g_pfstr.arr_num[i] = mask_xx[n % base];
		else
			g_pfstr.arr_num[i] = mask_x[n % base];
		i--;
		n /= base;
	}
	if (ft_check_is_flag('#') && g_pfstr.type_conv == 'o')
		ft_hesh_oct();
}
