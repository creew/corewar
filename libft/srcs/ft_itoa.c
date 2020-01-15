/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:04:16 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 16:52:08 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_int_len(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		nb;
	int		index;

	index = 0;
	nb = n;
	s = ft_strnew(calc_int_len(n));
	if (s == NULL)
		return (NULL);
	if (nb == 0)
		s[index++] = '0';
	else
	{
		while (nb)
		{
			s[index++] = ABS(nb % 10) + '0';
			nb /= 10;
		}
		if (n < 0)
			s[index++] = '-';
	}
	s[index] = '\0';
	return (ft_strrev(s));
}
