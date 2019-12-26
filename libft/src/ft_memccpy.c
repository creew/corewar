/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:41:59 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if (dest == 0 && src == 0)
		return ((void *)dest);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		p_dest[i] = p_src[i];
		if (p_dest[i] == (unsigned char)c)
			return (((void *)dest) + (i + 1));
		i++;
	}
	return (0);
}
