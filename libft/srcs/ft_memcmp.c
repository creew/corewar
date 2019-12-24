/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:30:30 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/06 15:14:56 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;
	size_t				count;

	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (us1[count] != us2[count])
			return (us1[count] - us2[count]);
		count++;
	}
	return (0);
}
