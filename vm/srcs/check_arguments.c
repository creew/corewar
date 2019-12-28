/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:21:25 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/26 17:21:25 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_reg(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;
	long	r;

	valid = INVALID;
	if (op->args[id] & T_REG)
	{
		r = read_be_map(runner->field, pr->pc + runner->skip, 1, 1);
		if (r >= 1 && r <= REG_NUMBER)
		{
			runner->args[id] = r - 1;
			valid = VALID;
		}
	}
	runner->skip++;
	return (valid);
}

static int	check_dir(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;
	t_uint	size;

	valid = INVALID;
	size = op->is_tdir_2bytes ? DIR_SIZE / 2 : DIR_SIZE;
	if (op->args[id] & T_DIR)
	{
		runner->args[id] = read_be_map(runner->field, pr->pc + runner->skip,
			size, 1);
		valid = VALID;
	}
	runner->skip += size;
	return (valid);
}

static int	check_ind(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;

	valid = INVALID;
	if (op->args[id] & IND_CODE)
	{
		runner->args[id] = read_be_map(runner->field, pr->pc + runner->skip
			, IND_SIZE, 1);
		valid = VALID;
	}
	runner->skip += IND_SIZE;
	return (valid);
}


static int	check_one_type(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	t_uint	arg_val;

	arg_val = (runner->arg >> ((3u - id) << 1u)) & 0x3u;
	runner->types[id] = arg_val;
	if (arg_val == REG_CODE)
		return (check_reg(op, id, pr, runner));
	if (arg_val == DIR_CODE)
		return (check_dir(op, id, pr, runner));
	if (arg_val == IND_CODE)
		return (check_ind(op, id, pr, runner));
	return (INVALID);
}

t_uint				calc_argtype(t_op *op)
{
	t_uint		arg_type;
	t_uint		i;

	arg_type = 0;
	i = -1;
	while (++i < op->args_count)
	{
		if (op->args[i] & T_REG)
			arg_type |= REG_CODE << ((3u - i) << 1u);
		else if (op->args[i] & T_DIR)
			arg_type |= DIR_CODE << ((3u - i) << 1u);
		else if (op->args[i] & T_IND)
			arg_type |= IND_CODE << ((3u - i) << 1u);
	}
	return (arg_type);
}

int			check_arguments(t_process *pr, t_runner *run, int index)
{
	t_op		*op;
	int			i;
	int			valid;

	valid = VALID;
	if ((op = get_op_by_id(index)) == NULL)
		return (INVALID);
	if (op->is_argtype)
		run->arg = (t_uint)read_be_map(run->field, pr->pc + run->skip++,
			1, UNSIGNED);
	else
		run->arg = calc_argtype(op_tab);
	i = -1;
	while (++i < op->args_count)
	{
		if (check_one_type(op, i, pr, run) != 0)
			valid = INVALID;
	}
	return (valid);
}
