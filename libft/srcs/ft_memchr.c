/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:23:09 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 11:27:35 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*arr;
	unsigned char		ch;
	size_t				count;

	count = 0;
	arr = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (count < n)
	{
		if (arr[count] == ch)
			return ((void *)(arr + count));
		count++;
	}
	return (NULL);
}
