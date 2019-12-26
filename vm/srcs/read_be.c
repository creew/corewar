/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_be.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:50:47 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 13:50:47 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_ushort	swap_ushort_be(t_ushort a)
{
	return (a >> 8u | ((a & 0xFFu) << 8u));
}

t_uint		swap_uint_be(t_uint a)
{
	return (a >> 24u | ((a >> 8u) & 0xFF00u) |
		((a & 0xFF00u) << 8u) | ((a & 0xFFu) << 24u));
}

void		write_varlen_be(t_uchar *data, t_ulong val, t_uint size)
{
	while (size > 0)
	{
		data[size - 1] = val & 0xFFu;
		val >>= 8u;
		size--;
	}
}

t_ulong		read_varlen_be(const t_uchar *data, t_uint size)
{
	t_ulong val;
	t_uint	i;

	i = 0;
	val = 0;
	while (i < size)
	{
		val <<= 8u;
		val |= data[i];
		i++;
	}
	return (val);
}
