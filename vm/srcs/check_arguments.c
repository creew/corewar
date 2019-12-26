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

extern t_op    op_tab[17];

t_op	*get_op_by_id(t_uint id)
{
	t_uint	i;

	i = -1;
	while (op_tab[++i].name)
	{
		if (op_tab[i].opcode == id)
			return (op_tab + i);

	}
	return (NULL);
}

static int	check_reg(t_op *op, t_uint id, t_runner *runner, int *skip)
{
	int		valid;

	valid = 1;
	if (op->args[id] & T_REG)
	{
		if (read_register(runner->field, runner->pr->pc + *skip,
			NULL, &runner->args[id]) == 0)
			valid = 0;
	}
	(*skip)++;
	return (valid);
}

static int	check_dir(t_op *op, t_uint id, t_runner *runner, int *skip)
{
	int		valid;
	t_uint	size;

	valid = 1;
	size = op->is_tdir_2bytes ? DIR_SIZE / 2 : DIR_SIZE;
	if (op->args[id] & T_DIR)
	{
		runner->args[id] = read_be_map(runner->field, runner->pr->pc + *skip,
			size, 1);
		valid = 0;
	}
	(*skip) += size;
	return (valid);
}

static int	check_ind(t_op *op, t_uint id, t_runner *runner, int *skip)
{
	int		valid;
	t_uint	size;

	valid = 1;
	size = op->is_tdir_2bytes ? DIR_SIZE / 2 : DIR_SIZE;
	if (op->args[id] & IND_CODE)
	{
		runner->args[id] = read_be_map(runner->field, runner->pr->pc + *skip
			, IND_SIZE, 1);
		valid = 0;
	}
	(*skip) += IND_SIZE;
	return (valid);
}


static int	check_one_type(t_op *op, t_uint id, t_runner *runner, int *skip)
{
	int		valid;
	t_uint	arg_val;

	valid = 0;
	arg_val = runner->arg >> ((3u - id) << 1u);
	runner->types[id] = arg_val;
	if (arg_val == REG_CODE)
	{
		if (check_reg(op, id, runner, skip) != 0)
			valid = 1;
	}
	else if (arg_val == DIR_CODE)
	{
		if (check_dir(op, id, runner, skip) != 0)
			valid = 1;
	}
	else if (arg_val == IND_CODE)
	{
		if (check_ind(op, id, runner, skip) != 0)
			valid = 1;
	}
	else if (arg_val == 0 && op->args[id] != 0)
		valid = 1;
	return (valid);
}

int			check_arguments(t_vm *vm, t_process *pr, int index, int *skip)
{
	t_op		*op;
	int			i;
	int			valid;
	t_runner	runner;

	ft_bzero(&runner, sizeof(runner));
	runner.field = vm->field;
	runner.pr = pr;
	valid = 0;
	if ((op = get_op_by_id(index)) == NULL)
		return (1);
	if (op->is_argtype)
	{
		runner.arg = (t_uint)read_be_map(vm->field, pr->pc + 1, 1, 0);
		(*skip)++;
		i = -1;
		while (++i < 3)
		{
			if (check_one_type(op, i, &runner, skip) != 0)
				valid = 1;
		}
	}
	return (valid);
}