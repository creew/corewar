/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:19:09 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t g;

	i = 0;
	j = 0;
	g = 0;
	if (n <= (size_t)(ft_strlen(dest)))
		return (ft_strlen(src) + n);
	while (dest[i] != '\0')
	{
		i++;
		g++;
	}
	while (src[j] != '\0' && i < (n - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(src) + g);
}
