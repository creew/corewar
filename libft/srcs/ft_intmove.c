/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:51:17 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/27 10:25:55 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intmove(int *dst, int *src, size_t size)
{
	if (dst < src)
	{
		while (size--)
			*dst++ = *src++;
	}
	else if (dst > src)
	{
		while (size--)
			dst[size] = src[size];
	}
}
