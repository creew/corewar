/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:58:35 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 12:02:17 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *data, size_t old_size, size_t new_size)
{
	void	*new_mem;

	new_mem = ft_memalloc(new_size);
	if (new_mem)
		if (data)
			ft_memcpy(new_mem, data, old_size);
	ft_memdel(&data);
	return (new_mem);
}
