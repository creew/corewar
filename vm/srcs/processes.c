/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:18:09 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 17:18:09 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

void (*g_asm_funcs[])(t_process *pr, t_runner *run) = {
	process_live_run,
	process_ld_run,
	process_st_run,
	process_add_run,
	process_sub_run,
	process_and_run,
	process_or_run,
	process_xor_run,
	process_zjmp_run,
	process_ldi_run,
	process_sti_run,
	process_fork_run,
	process_lld_run,
	process_lldi_run,
	process_lfork_run,
	process_aff_run
};

void	process_waiting(t_vm *vm, t_process *pr)
{
	t_runner	run;

	if (pr->wait > 0)
		pr->wait--;
	if (pr->wait == 0)
	{
		run.skip = 1;
		if (pr->opcode >= 1 && pr->opcode <= 16)
		{
			run.field = vm->field;
			run.processes_root = &vm->processes_root;
			run.process_max = &vm->process_max;
			run.pc = pr->pc;
			ft_putnbr(pr->opcode);
			ft_putendl(get_op_by_id(pr->opcode)->name);
			if (check_arguments(&run, pr->opcode) == 0)
				g_asm_funcs[pr->opcode - 1](pr, &run);
		}
		pr->pc += run.skip;
		pr->pc %= MEM_SIZE;
		pr->state = NOT_INITED;
	}
}

void	process_processes(t_vm *vm)
{
	t_process	*pr;
	t_uchar		id;
	t_op		*op;

	pr = vm->processes_root;
	while (pr)
	{
		if (pr->state == NOT_INITED)
		{
			id = read_be_map(vm->field, pr->pc, 1, 0);
			if ((op = get_op_by_id(id)) != NULL)
				pr->wait = op->wait;
			else
				pr->wait = 0;
			pr->state = WAITING;
			pr->opcode = id;
		}
		if (pr->state == WAITING)
			process_waiting(vm, pr);
		pr = pr->next;
	}
}