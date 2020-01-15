/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_live_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:32:31 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:32:34 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_live_run(t_vm *vm, t_process *pr, t_runner *run)
{
	t_player	*pl;
	long		index;

	pr->cycle_live = vm->cycles;
	vm->live++;
	if (vm->visualize)
		vm->field[pr->pc % MEM_SIZE].live = 50;
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | live %ld\n", pr->id, run->args[A1]);
	index = -run->args[A1];
	if (index >= 1 && index <= (int)vm->count_players)
	{
		pl = vm->players[index - 1];
		if (!vm->do_debug && !vm->do_dump)
			ft_printf("A process shows that player %d (%s) is alive\n",
				-run->args[A1], pl->name);
		vm->last_player = pl;
		pl->last_live = vm->cycles;
		pl->live_in_session++;
		if (vm->debug_args & VERB_SHOW_LIVES)
			ft_printf("Player %d (%s) is said to be alive\n",
				pl->player_id, pl->name);
	}
}
