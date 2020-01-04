/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_field.c                                       :+:      :+:    :+:   */
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
	t_uint 		i;
	t_uint		j;
	size_t		size;
	t_player	*pl;
	t_uint		start;

	vm->process_max = 1;
	i = -1;
	size = ft_array_size(&vm->players);
	while (ft_array_get(&vm->players, ++i, (void **)&pl) == 0)
	{
		start = ((sizeof(vm->field) / sizeof (*vm->field)) / size) * i;
		j = -1;
		while (++j < pl->prog_size)
		{
			vm->field[start + j].cmd = pl->prog[j];
			vm->field[start + j].id = pl->player_id;
		}
		add_process(&vm->processes_root, pl->player_id, start, &vm->process_max);
	}
	vm->state = RUNNING;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycles_check = vm->cycle_to_die;
	vm->live = 0;
	init_visu(vm);
}
