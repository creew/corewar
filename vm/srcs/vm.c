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

void    infinite_loop(t_vm *vm)
{
    while (!is_winner_exist())
    {
        if (vm->visualize)
        {
            if (process_event(&vm->vis, vm) == 0)
                break;
            draw_all(&vm->vis, vm);
        }
        if (vm->started || vm->do_steps)
        {
        	if (vm->do_steps)
        		vm->do_steps--;
            process_processes(vm);
            inc_counter(vm);
        }
    }
}

int main(int ac, char *av[])
{
	t_player	*pl;
	t_vm		vm;

	int n = read_option(ac, av);
	if ((ac - n) > MAX_PLAYERS)
		return (ERR_TO_MUCH_PLAYERS);
	ft_bzero(&vm, sizeof(vm));
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
	infinite_loop(&vm);
	sdl_destroy(&vm.vis);
}
