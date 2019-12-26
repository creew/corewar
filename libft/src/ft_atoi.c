/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:37:27 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int					ft_return_int(int i, unsigned char *str)
{
	int						minus;
	unsigned long long int	base;

	minus = 0;
	base = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] < 48 || str[i + 1] > 57)
			return (0);
		if (str[i] == 45)
			minus = 1;
		i++;
	}
	base = base + (str[i] - '0');
	i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		base = base * 10 + (str[i] - '0');
		i++;
	}
	if ((base > 9223372036854775807 && minus == 0) || (i > 19 && minus == 0))
		return (-1);
	if ((base > 9223372036854775807 && minus == 1) || (i > 19 && minus == 1))
		return (0);
	return (minus == 1 ? base * (-1) : base);
}

int							ft_atoi(const char *src)
{
	int						i;
	unsigned char			*str;

	str = ((unsigned char *)src);
	i = 0;
	while ((str[i] != '\0'))
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-') &&
		(str[i] != '+') && (str[i] != ' ') && (str[i] != '\t')
		&& (str[i] != '\n')
		&& (str[i] != '\r') && (str[i] != '\v') && (str[i] != '\f'))
			return (0);
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')
		|| (str[i] == '+'))
			return (ft_return_int(i, str));
		i++;
	}
	return (0);
}
