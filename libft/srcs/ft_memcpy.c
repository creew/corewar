/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:00:43 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/05 19:44:19 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*to;
	const unsigned char	*from;
	size_t				count;

	from = (const unsigned char *)src;
	to = (unsigned char *)dst;
	if (from == to)
		return (dst);
	count = 0;
	while (count < n)
	{
		to[count] = from[count];
		count++;
	}
	return (dst);
}
