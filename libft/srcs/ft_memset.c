/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:58:44 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 11:06:10 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*arr;
	size_t			count;

	count = 0;
	ch = (unsigned char)c;
	arr = (unsigned char *)b;
	while (count < len)
		arr[count++] = ch;
	return (b);
}
