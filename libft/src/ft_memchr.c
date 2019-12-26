/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:27:44 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)arr;
	i = 0;
	while (n--)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
