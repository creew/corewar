/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:54:30 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 16:54:31 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_visu(t_vm *vm)
{
	if (vm->visualize)
	{
		if (init_sdl(&vm->vis) != 0)
		{
			ft_putendl("Error initialize sdl");
			sdl_destroy(&vm->vis);
			vm->visualize = 0;
		}
		else
			vm->state = PAUSED;
	}
}

void		init_vm(t_vm *vm)
{
	t_uint		i;
	t_uint		j;
	t_player	*pl;
	t_uint		start;

	i = -1;
	while (++i < vm->count_players)
	{
		pl = vm->players[i];
		start = ((sizeof(vm->field) / sizeof(*vm->field)) / vm->count_players)
			* i;
		j = -1;
		while (++j < pl->prog_size)
		{
			vm->field[start + j].cmd = pl->prog[j];
			vm->field[start + j].id = pl->player_id;
		}
		add_process(&vm->processes_root, pl->player_id, start,
			&vm->process_count);
	}
	vm->state = RUNNING;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycles_check = vm->cycle_to_die;
	init_visu(vm);
}
