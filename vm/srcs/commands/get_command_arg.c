/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:45:48 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:45:49 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_ulong			get_reg_dir_ind_arg(t_process *pr, t_runner *run, t_uint arg)
{
	t_ulong		val;

	if (run->types[arg] == REG_CODE)
		val = read_varlen_be(pr->regs[run->args[arg]], sizeof(pr->regs[0]),
			SIGNED);
	else if (run->types[arg] == DIR_CODE)
		val = run->args[arg];
	else
		val = read_be_map(run->field, pr->pc + (run->args[arg] % IDX_MOD),
			DIR_SIZE, SIGNED);
	return (val);
}

t_ulong			get_reg_dir_arg(t_process *pr, t_runner *run, t_uint arg)
{
	t_ulong		val;

	if (run->types[arg] == REG_CODE)
		val = read_varlen_be(pr->regs[run->args[arg]], sizeof(pr->regs[0]),
			SIGNED);
	else
		val = run->args[arg];
	return (val);
}

t_ulong			get_dir_ind_arg(t_process *pr, t_runner *run, t_uint arg)
{
	t_ulong		val;

	if (run->types[arg] == DIR_CODE)
		val = run->args[arg];
	else
		val = read_be_map(run->field, pr->pc + (run->args[arg] % IDX_MOD),
			DIR_SIZE, SIGNED);
	return (val);
}
