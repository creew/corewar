/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:04:41 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 11:06:24 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*to;
	const unsigned char	*from;
	unsigned char		ch;
	size_t				count;

	ch = c;
	from = (const unsigned char *)src;
	to = (unsigned char *)dst;
	count = 0;
	while (count < n)
	{
		to[count] = from[count];
		if (from[count++] == ch)
			return (to + count);
	}
	return (NULL);
}
