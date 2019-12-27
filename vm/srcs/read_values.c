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

void	set_field_vals(t_fieldelem *field, long pos, t_process *pr, long reg)
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
