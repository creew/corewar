/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:07:13 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 11:21:28 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*to;
	const unsigned char	*from;
	size_t				count;

	to = (unsigned char *)dst;
	from = (const unsigned char *)src;
	if (from == to)
		return (dst);
	if (from > to)
	{
		count = 0;
		while (count < len)
		{
			to[count] = from[count];
			count++;
		}
	}
	else
		while (len > 0)
		{
			to[len - 1] = from[len - 1];
			len--;
		}
	return (dst);
}
