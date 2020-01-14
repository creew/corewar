/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:18:09 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 17:18:09 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <ft_printf.h>

static void		remove_unlive(t_vm *vm)
{
	t_process	*pr;
	t_process	*next;

	pr = vm->processes_root;
	while (pr)
	{
		next = pr->next;
		if (vm->cycles - pr->cycle_live >=
			(vm->cycle_to_die >= 0 ? vm->cycle_to_die : 0))
		{
			if (vm->debug_args & VERB_SHOW_DEATHS)
				ft_printf("Process %zu hasn't lived for %d cycles (CTD %d)\n",
					pr->id, vm->cycles - pr->cycle_live, vm->cycle_to_die);
			remove_process(&vm->processes_root, pr, &vm->process_count);
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

void			process_cycle(t_vm *vm)
{
	t_process	*pr;

	vm->cycles_check--;
	if (vm->debug_args & VERB_SHOW_CYCLES)
		ft_printf("It is now cycle %zu\n", vm->cycles);
	pr = vm->processes_root;
	while (pr)
	{
		exec_process(vm, pr);
		pr = pr->next;
	}
	if (!vm->cycles_check)
		check_ctd(vm);
}
