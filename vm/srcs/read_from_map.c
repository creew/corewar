/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:43:45 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 18:43:46 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

long		read_be_map(const t_fieldelem *data, int offset,
	t_uint size, int boolean)
{
	t_ulong		val;
	t_uint		i;

	i = 0;
	val = 0;
	while (offset < 0)
		offset += MEM_SIZE;
	while (i < size)
	{
		val <<= 8u;
		val |= data[(offset + i) % MEM_SIZE] & 0xFFu;
		i++;
	}
	if (boolean && (val >> ((i << 3u) - 1u)) & 1u)
	{
		while (i < sizeof(val))
		{
			val |= (0xFFul << (i << 3u));
			i++;
		}
	}
	return (val);
}

void		write_be_map(t_fieldelem *data, t_uint val, t_uint offset, t_uint size)
{
	while (size > 0)
	{
		data[(offset + size - 1) % MEM_SIZE] = val & 0xFFu;
		val >>= 8u;
		size--;
	}
}