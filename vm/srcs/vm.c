/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:32:42 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 13:32:43 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#include <ft_printf.h>

static void		infinite_loop(t_vm *vm)
{
    while (42)
    {
		if (vm->do_dump && vm->dump_n == vm->cycles)
		{
			create_dump(vm, 32);
			break ;
		}
		if (vm->visualize)
		{
			if (process_event(&vm->vis, vm) == 0)
				break ;
			draw_all(&vm->vis, vm);
		}
		if (vm->state == RUNNING || (vm->state == PAUSED && vm->do_steps))
		{
			if (vm->do_steps)
				vm->do_steps--;
			inc_counter(vm);
			process_processes(vm);
		}
		if (vm->processes_root == NULL)
		{
			vm->state = FINISHED;
			if (vm->last_player)
				ft_printf("Contestant %d, \"%s\", has won !\n",
					vm->last_player->player_id, vm->last_player->name);
			if (!vm->visualize)
				break ;
		}
    }
}

static void		print_players(t_arrplayers *players)
{
	size_t		index;
	t_player	*pl;

	index = -1;
	while ((ft_array_get(players, ++index, (void **)&pl)) == 0)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			pl->player_id, pl->prog_size, pl->name, pl->comment);
}

void			destroy_all(t_vm *vm)
{
	t_arrplayers	*players;
	t_process		*pr;
	t_process		*prnext;

	players = &vm->players;
	ft_array_delete_all(&players, free);
	pr = vm->processes_root;
	vm->processes_root = NULL;
	while (pr)
	{
		prnext = pr->next;
		ft_memdel((void **)&pr);
		pr = prnext;
	}
	sdl_destroy(&vm->vis);
}

int				main(int ac, char *av[])
{
	t_vm		vm;
	t_result	res;

	ft_bzero(&vm, sizeof(vm));
	ft_array_init(&vm.players, 0);
	if ((res = read_option(&vm, ac, av)) == RET_OK)
	{
		init_vm(&vm);
		ft_printf("Introducing contestants...\n");
		print_players(&vm.players);
		infinite_loop(&vm);
	}
	destroy_all(&vm);
	return (0);
}
