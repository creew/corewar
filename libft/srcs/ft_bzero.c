/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:02:22 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 11:03:00 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*sc;

	sc = (unsigned char *)s;
	while ((size_t)sc % sizeof(t_bzero_elem) && n)
	{
		*sc++ = 0;
		n--;
	}
	while (n >= sizeof(t_bzero_elem))
	{
		*(t_bzero_elem *)sc = 0;
		sc += sizeof(t_bzero_elem);
		n -= sizeof(t_bzero_elem);
	}
	while (n)
	{
		*sc++ = 0;
		n--;
	}
}
