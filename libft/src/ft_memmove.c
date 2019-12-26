/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:31:24 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char *pd;
	unsigned char *ps;

	if (dest == NULL && src == NULL)
		return ((void *)dest);
	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (pd <= ps || pd >= (ps + num))
	{
		while (num--)
			*pd++ = *ps++;
	}
	else
	{
		pd += num - 1;
		ps += num - 1;
		while (num--)
			*pd-- = *ps--;
	}
	return ((void *)dest);
}
