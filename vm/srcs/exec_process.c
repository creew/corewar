/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:28:13 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 12:28:14 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <ft_printf.h>

static void (*g_asm_funcs[])(t_vm *, t_process *pr, t_runner *run) = {
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

static void		process_action(t_vm *vm, t_process *pr, t_runner *run)
{
	int		i;

	run->field = vm->field;
	if (check_arguments(pr, run, pr->opcode) == VALID)
	{
		g_asm_funcs[pr->opcode - 1](vm, pr, run);
	}
	if (vm->debug_args & VERB_SHOW_MOVES && run->skip)
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ", run->skip, pr->pc,
			pr->pc + run->skip);
		i = -1;
		while (++i < run->skip)
			ft_printf("%02x ", run->field[(pr->pc + i) % MEM_SIZE].cmd);
		ft_printf("\n");
	}
}

static void		process_waiting(t_vm *vm, t_process *pr)
{
	t_runner	run;

	if (pr->wait > 0)
		pr->wait--;
	if (pr->wait == 0)
	{
		run.skip = 1;
		if (pr->opcode >= 1 && pr->opcode <= 16)
			process_action(vm, pr, &run);
		pr->pc += run.skip;
		if (pr->pc < 0)
			ft_putendl("Errr");
		if (pr->pc > MEM_SIZE)
			pr->pc %= MEM_SIZE;
		pr->state = NOT_INITED;
	}
}

void			exec_process(t_vm *vm, t_process *pr)
{
	t_uchar		id;
	t_op		*op;

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
}
