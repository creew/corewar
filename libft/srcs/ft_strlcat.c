/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:52:57 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/05 10:56:19 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		length;
	size_t		src_len;
	size_t		sz;

	sz = size;
	src_len = ft_strlen(src);
	length = ft_strlen(dst);
	if (size >= (length + 1))
	{
		size -= (length + 1);
		dst += length;
		while (size && *src)
		{
			*dst++ = *src++;
			size--;
		}
		*dst = '\0';
	}
	return (src_len + MIN(sz, length));
}
