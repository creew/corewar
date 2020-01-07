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

long		read_varlen_be(const t_uchar *data, t_uint size, int is_signed)
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
	if (is_signed == SIGNED && (val >> ((i << 3u) - 1u)) & 1u)
	{
		while (i < sizeof(val))
		{
			val |= (0xFFul << (i << 3u));
			i++;
		}
	}
	return (val);
}

long		read_be_map(const t_fieldelem *data, long offset,
						t_uint size, int is_signed)
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
		val |= data[(offset + i) % MEM_SIZE].cmd;
		i++;
	}
	if (is_signed == SIGNED && (val >> ((i << 3u) - 1u)) & 1u)
	{
		while (i < sizeof(val))
		{
			val |= (0xFFul << (i << 3u));
			i++;
		}
	}
	return (val);
}

void		set_field_vals(t_fieldelem *field, long pos, t_process *pr, long reg)
{
	t_uint	count;
	long	index;

	while (pos < 0)
		pos += MEM_SIZE;
	count = -1;
	while (++count < sizeof(pr->regs[0]))
	{
		index = (pos + count) % MEM_SIZE;
		field[index].cmd = pr->regs[reg][count];
		field[index].id = pr->player_id;
		field[index].fresh = 50;
		field[index].live = 0;
	}
}
