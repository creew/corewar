/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:45:21 by eklompus          #+#    #+#             */
/*   Updated: 2019/10/30 14:45:22 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	len = 0;
	if (dst && src)
	{
		len = ft_strlen(src);
		while (size > 1 && *src)
		{
			*dst++ = *src++;
			size--;
		}
		if (size)
			*dst = '\0';
	}
	return (len);
}
