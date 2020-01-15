/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:18:42 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 12:26:25 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		length;

	length = 0;
	while (length < len && src[length] != '\0')
	{
		dst[length] = src[length];
		length++;
	}
	while (length < len)
	{
		dst[length] = '\0';
		length++;
	}
	return (dst);
}
