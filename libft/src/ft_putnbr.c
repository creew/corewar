/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:27:14 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_negativ(int nb)
{
	ft_putchar('-');
	if (nb == -2147483648)
	{
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else
	{
		nb *= (-1);
		ft_putnbr(nb);
	}
}

void		ft_putnbr(int nb)
{
	int		arr[14];
	int		i;

	if (nb == 0)
		ft_putchar('0');
	i = 0;
	if (nb < 0)
		ft_negativ(nb);
	while (nb > 0)
	{
		arr[i] = nb % 10;
		nb /= 10;
		i++;
	}
	i -= 1;
	while (i - 1 >= -1)
	{
		ft_putchar(arr[i] + 48);
		i--;
	}
}
