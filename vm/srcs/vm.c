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

static int		check_cycle(t_vm *vm)
{
	int		ret;

	ret = 0;
	if (vm->state == RUNNING || (vm->state == PAUSED && vm->do_steps))
	{
		if (vm->do_steps)
			vm->do_steps--;
		inc_counter(vm);
		process_cycle(vm);
	}
	if (vm->processes_root == NULL)
	{
		vm->state = FINISHED;
		if (vm->last_player)
			ft_printf("Contestant %d, \"%s\", has won !\n",
				vm->last_player->player_id, vm->last_player->name);
		if (!vm->visualize)
			ret = 1;
	}
	return (ret);
}

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
		if (check_cycle(vm))
			break ;
	}
}

static void		print_players(t_player **players, size_t count)
{
	size_t		index;
	t_player	*pl;

	index = -1;
	while (++index < count)
	{
		pl = players[index];
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			pl->player_id, pl->prog_size, pl->name, pl->comment);
	}
}

void			destroy_all(t_vm *vm)
{
	t_process		*pr;
	t_process		*prnext;

	while (vm->count_players--)
		ft_memdel((void **)&vm->players[vm->count_players]);
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
	if ((res = read_option(&vm, ac, av)) == RET_OK)
	{
		init_vm(&vm);
		ft_printf("Introducing contestants...\n");
		print_players(vm.players, vm.count_players);
		infinite_loop(&vm);
	}
	else
	{
		if (res == ERR_NO_ARGUMENTS)
			print_usage();
		else
			print_error(res);
	}
	destroy_all(&vm);
	return (0);
}
