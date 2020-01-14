/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:37:55 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 12:37:56 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_reg(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;
	long	r;

	valid = INVALID;
	if (op->args[id] & T_REG)
	{
		r = read_be_map(runner->field, pr->pc + runner->skip, 1, SIGNED);
		if (r >= 1 && r <= REG_NUMBER)
		{
			runner->args[id] = r - 1;
			valid = VALID;
		}
	}
	runner->skip++;
	return (valid);
}

int		check_dir(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;
	t_uint	size;

	valid = INVALID;
	size = op->is_tdir_2bytes ? DIR_SIZE / 2 : DIR_SIZE;
	if (op->args[id] & T_DIR)
	{
		runner->args[id] = read_be_map(runner->field, pr->pc + runner->skip,
			size, SIGNED);
		valid = VALID;
	}
	runner->skip += size;
	return (valid);
}

int		check_ind(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;

	valid = INVALID;
	if (op->args[id] & T_IND)
	{
		runner->args[id] = read_be_map(runner->field, pr->pc + runner->skip,
			IND_SIZE, SIGNED);
		valid = VALID;
	}
	runner->skip += IND_SIZE;
	return (valid);
}
