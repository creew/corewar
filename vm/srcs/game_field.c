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
	}
}

void		init_vm(t_vm *vm)
{
	t_uint 		i;
	t_uint		j;
	size_t		size;
	t_player	*pl;
	t_uint		start;

	i = -1;
	size = ft_array_size(&vm->players);
	while (ft_array_get(&vm->players, ++i, (void **)&pl) == 0)
	{
		start = ((sizeof(vm->field) / sizeof (*vm->field)) / size) * i;
		j = -1;
		while (++j < pl->prog_size)
			vm->field[start + j] = pl->prog[j] | ((i + 1u) << 8u);
		add_process(&vm->processes_root, (1 + i), start, &vm->process_max);
	}
	vm->cycle_decrease = CYCLE_TO_DIE;
	vm->live = 0;
	init_visu(vm);
}