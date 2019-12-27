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

	valid = 1;
	if (op->args[id] & T_REG)
	{
		if (read_register(runner->field, pr->pc + runner->skip,
			NULL, &runner->args[id]) == 0)
			valid = 0;
	}
	runner->skip++;
	return (valid);
}

static int	check_dir(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;
	t_uint	size;

	valid = 1;
	size = op->is_tdir_2bytes ? DIR_SIZE / 2 : DIR_SIZE;
	if (op->args[id] & T_DIR)
	{
		runner->args[id] = read_be_map(runner->field, pr->pc + runner->skip,
			size, 1);
		valid = 0;
	}
	runner->skip += size;
	return (valid);
}

static int	check_ind(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;

	valid = 1;
	if (op->args[id] & IND_CODE)
	{
		runner->args[id] = read_be_map(runner->field, pr->pc + runner->skip
			, IND_SIZE, 1);
		valid = 0;
	}
	runner->skip += IND_SIZE;
	return (valid);
}


static int	check_one_type(t_op *op, t_uint id, t_process *pr, t_runner *runner)
{
	int		valid;
	t_uint	arg_val;

	valid = 0;
	arg_val = (runner->arg >> ((3u - id) << 1u)) & 0x3u;
	runner->types[id] = arg_val;
	if (arg_val == REG_CODE)
	{
		if (check_reg(op, id, pr, runner) != 0)
			valid = 1;
	}
	else if (arg_val == DIR_CODE)
	{
		if (check_dir(op, id, pr, runner) != 0)
			valid = 1;
	}
	else if (arg_val == IND_CODE)
	{
		if (check_ind(op, id, pr, runner) != 0)
			valid = 1;
	}
	else if (arg_val == 0 && op->args[id] != 0)
		valid = 1;
	return (valid);
}

t_uint		calc_argtype(t_op *op)
{
	t_uint		arg_type;
	t_uint		i;

	arg_type = 0;
	i = -1;
	while (++i < 3)
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

	valid = 0;
	if ((op = get_op_by_id(index)) == NULL)
		return (1);
	if (op->is_argtype)
	{
		run->arg = (t_uint) read_be_map(run->field, pr->pc + 1, 1, 0);
		run->skip++;
	}
	else
		run->arg = calc_argtype(op_tab);
	i = -1;
	while (++i < 3)
	{
		if (check_one_type(op, i, pr, run) != 0)
		valid = 1;
	}
	return (valid);
}
