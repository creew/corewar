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

t_op	*get_op_by_id(int id)
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

void (*g_asm_funcs[])(t_vm *, t_process *pr, t_runner *run) = {
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
			if (check_arguments(pr, &run, pr->opcode) == 0)
				g_asm_funcs[pr->opcode - 1](vm, pr, &run);
		}
		pr->pc += run.skip;
		if (pr->pc < 0)
			ft_putendl("Errr");
		if (pr->pc > MEM_SIZE)
			pr->pc %= MEM_SIZE;
		pr->state = NOT_INITED;
	}
}

void	set_cycle_to_die(t_vm *vm)
{
	vm->cycle_to_die = vm->cycle_to_die - CYCLE_DELTA;
	if (vm->cycle_to_die < 1)
		vm->cycle_to_die = 1;
	vm->checks = 0;
	if (vm->debug_args & VERB_SHOW_CYCLES)
		ft_printf("Cycle to die is now %zu\n", vm->cycle_to_die);
}


void	process_processes(t_vm *vm)
{
	t_process	*pr;
	t_uchar		id;
	t_op		*op;
	t_process	*next;
	t_player	*pl;
	size_t		i;

	pr = vm->processes_root;
	vm->cycles_check--;
	if (vm->debug_args & VERB_SHOW_CYCLES)
		ft_printf("It is now cycle %zu\n", vm->cycles);
	while (pr)
	{
		next = pr->next;
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
		if (!vm->cycles_check)
		{
			if (vm->cycles - pr->cycle_live >= vm->cycle_to_die)
			{
				if (vm->debug_args & VERB_SHOW_DEATHS)
					ft_printf("Process %zu hasn't lived for %d cycles (CTD %d)\n",
							  pr->id, vm->cycles - pr->cycle_live, vm->cycle_to_die);
				remove_process(&vm->processes_root, pr);
			}
		}
		pr = next;
	}
	if (!vm->cycles_check)
	{
		if (vm->live >= NBR_LIVE)
			set_cycle_to_die(vm);
		else
		{
			if (++vm->checks == MAX_CHECKS)
				set_cycle_to_die(vm);
		}
		vm->cycles_check = vm->cycle_to_die;
		vm->live = 0;
		i = -1;
		while (ft_array_get(&vm->players, ++i, (void **)&pl) == 0)
			pl->live_in_session = 0;
	}
}