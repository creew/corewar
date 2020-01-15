/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:29:43 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 11:33:43 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memndup(const void *mem, size_t size)
{
	void	*m1;

	m1 = ft_memalloc(size);
	if (m1 && mem && size)
		ft_memcpy(m1, mem, size);
	return (m1);
}
