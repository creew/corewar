/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:41:30 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/26 19:41:34 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	set_field_vals(t_fieldelem *field, int pos, t_process *pr, int reg)
{
	t_uint count;

	while (pos < 0)
		pos += MEM_SIZE;
	count = -1;
	while (++count < sizeof(pr->regs[0]))
	{
		field[(pos + count) % MEM_SIZE] = pr->regs[reg - 1][count] |
										  ((pr->player_id) << 8u);
	}
}

int		read_register(t_fieldelem *fieldelem, int pos, int *offset, long *reg)
{
	long r;

	r = read_be_map(fieldelem, pos + (offset ? *offset : 0), 1, 1);
	if (offset)
		(*offset) += 1;
	if (r >= 1 && r <= REG_NUMBER)
	{
		*reg = r;
		return (0);
	}
	return (1);
}

int		read_reg_val(t_fieldelem *fieldelem, t_process *pr, int *offset, long *val)
{
	long reg;

	if (read_register(fieldelem, pr->pc, offset, &reg) == 0)
	{
		*val = read_varlen_be(pr->regs[reg - 1], sizeof(pr->regs[0]));
		return (0);
	}
	return (1);
}


long	read_ind(t_fieldelem *field, int pos, int *offset, int is_idx)
{
	long res;
	long ind;

	ind = read_be_map(field, pos + *offset, IND_SIZE, 1);
	(*offset) += IND_SIZE;
	if (is_idx)
		ind = ind % IDX_MOD;
	res = read_be_map(field, pos + ind, DIR_SIZE, 1);
	return (res);
}

long	read_dir(t_fieldelem *field, int pos, int *offset, int is_half)
{
	long	res;
	t_uint	size;

	size = is_half ? DIR_SIZE / 2 : DIR_SIZE;
	res = read_be_map(field, pos + (offset ? *offset : 0), size, 1);
	if (offset)
		(*offset) += size;
	return (res);
}