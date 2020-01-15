/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:45:24 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/04 19:23:17 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rostring(char *s, int len)
{
	int		index;
	char	c;

	index = 0;
	while (index < len / 2)
	{
		c = s[index];
		s[index] = s[len - index - 1];
		s[len - index - 1] = c;
		index++;
	}
	return (s);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	buf[64];
	int		nb;
	int		index;

	index = 0;
	nb = n;
	if (nb == 0)
		buf[index++] = '0';
	else
	{
		while (nb)
		{
			buf[index++] = ABS(nb % 10) + '0';
			nb /= 10;
		}
		if (n < 0)
			buf[index++] = '-';
	}
	buf[index] = '\0';
	rostring(buf, index);
	ft_putstr_fd(buf, fd);
}
