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

int 	is_winner_exist()
{
	return (0);
}

int main(int ac, char *av[])
{
	t_player	*pl;
	t_vm		vm;

	int n = read_option(ac, av);
	if ((ac - n) > MAX_PLAYERS)
		return (ERR_TO_MUCH_PLAYERS);
	ft_bzero(&vm, sizeof(vm));
	vm.delay = 1000;
	vm.visualize = 1;
	ft_array_init(&vm.players, 0);
	while (n < ac)
	{
		if (read_champ(av[n], &pl) != RET_OK)
			break;
		ft_array_insert(&vm.players, pl, 0);
		n++;
	}
	init_vm(&vm);
	if (vm.visualize)
	{
		if (init_sdl(&vm.vis) != 0)
		{
			ft_putendl("Error initialize sdl");
			sdl_destroy(&vm.vis);
			vm.visualize = 0;
		}
	}
	while (!is_winner_exist())
	{
		if (vm.visualize)
		{
			if (process_event(&vm.vis) == 0)
				break;
			draw_all(&vm.vis, &vm);
		}
		if (vm.started)
		{


		}
	}
	sdl_destroy(&vm.vis);
}
