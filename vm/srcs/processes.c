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

static void		process_waiting(t_vm *vm, t_process *pr)
{
	t_runner	run;
	int         i;

	if (pr->wait > 0)
		pr->wait--;
	if (pr->wait == 0)
	{
		run.skip = 1;
		if (pr->opcode >= 1 && pr->opcode <= 16)
		{
			run.field = vm->field;
			if (check_arguments(pr, &run, pr->opcode) == 0)
            {
			    g_asm_funcs[pr->opcode - 1](vm, pr, &run);
			    if (vm->debug_args & VERB_SHOW_MOVES && run.skip)
                {
			        ft_printf("ADV %d (0x%04x -> 0x%04x) ", run.skip, pr->pc, pr->pc + run.skip);
			        i = -1;
			        while (++i < run.skip)
			            ft_printf("%02x ", run.field[(pr->pc + i) % MEM_SIZE].cmd);
			        ft_printf("\n");
                }
            }
		}
		pr->pc += run.skip;
		if (pr->pc < 0)
			ft_putendl("Errr");
		if (pr->pc > MEM_SIZE)
			pr->pc %= MEM_SIZE;
		pr->state = NOT_INITED;
	}
}

static void		remove_unlive(t_vm *vm)
{
	t_process	*pr;
	t_process	*next;

	pr = vm->processes_root;
	while (pr)
	{
		next = pr->next;
		if (vm->cycles - pr->cycle_live >= (vm->cycle_to_die >= 0 ? vm->cycle_to_die : 0))
		{
			if (vm->debug_args & VERB_SHOW_DEATHS)
				ft_printf("Process %zu hasn't lived for %d cycles (CTD %d)\n",
						  pr->id, vm->cycles - pr->cycle_live, vm->cycle_to_die);
			remove_process(&vm->processes_root, pr);
		}
		pr = next;
	}
}

static void		check_ctd(t_vm *vm)
{
	size_t		i;

	remove_unlive(vm);
	if (vm->live >= NBR_LIVE || ++vm->checks == MAX_CHECKS)
	{
		vm->cycle_to_die = vm->cycle_to_die - CYCLE_DELTA;
		vm->checks = 0;
		if (vm->debug_args & VERB_SHOW_CYCLES)
			ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
	}
	vm->cycles_check = vm->cycle_to_die > 1 ? vm->cycle_to_die : 1;
	vm->live = 0;
	i = -1;
	while (++i < vm->count_players)
		vm->players[i]->live_in_session = 0;
}

static void		do_process(t_vm *vm, t_process *pr)
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

void	process_processes(t_vm *vm)
{
	t_process	*pr;

	vm->cycles_check--;
	if (vm->debug_args & VERB_SHOW_CYCLES)
		ft_printf("It is now cycle %zu\n", vm->cycles);
	pr = vm->processes_root;
	while (pr)
	{
		do_process(vm, pr);
		pr = pr->next;
	}
	if (!vm->cycles_check)
		check_ctd(vm);
}
