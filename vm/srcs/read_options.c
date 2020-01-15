/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:09:03 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 15:09:03 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				is_player_index_free(t_player **arr, int player_id, size_t size)
{
	if (player_id <= (int)(size / sizeof(arr[0])) && player_id >= 1)
	{
		if (arr[player_id - 1] == NULL)
			return (1);
	}
	return (0);
}

t_result		get_next_free_index(t_player **arr, int *player_id, size_t size)
{
	size_t		i;

	i = 0;
	while (++i <= size / sizeof(arr[0]))
	{
		if (is_player_index_free(arr, i, size))
		{
			*player_id = i;
			return (RET_OK);
		}
	}
	return (ERR_CANT_ASSIGN_INDEX);
}

static t_result	check_order(t_player **arr, size_t count)
{
	size_t		i;

	i = -1;
	while (++i < count)
	{
		if (arr[i] == NULL)
			return (ERR_INCORRECT_ORDER_PLAYERS);
	}
	return (RET_OK);
}

static t_result	join_players(t_vm *vm)
{
	size_t		index;
	t_result	err;
	int			res;

	index = -1;
	while (++index < vm->count_pl_tmp)
	{
		err = get_next_free_index(vm->players, &res, sizeof(vm->players));
		if (err != RET_OK)
			return (err);
		vm->pl_tmp[index]->player_id = res;
		vm->players[res - 1] = vm->pl_tmp[index];
		vm->count_players++;
	}
	ft_bzero(vm->pl_tmp, sizeof(vm->pl_tmp));
	vm->count_pl_tmp = 0;
	return (RET_OK);
}

t_result		read_option(t_vm *vm, int ac, char *av[])
{
	int			count;
	t_result	res;

	if (ac < 2)
		return (ERR_NO_ARGUMENTS);
	count = 1;
	while (count < ac)
	{
		if ((res = parse_arg(vm, &count, ac, av)) != RET_OK)
			return (res);
		count++;
	}
	if (vm->count_players + vm->count_pl_tmp < 2)
		return (ERR_TO_LITTLE_PLAYERS);
	if (vm->count_players + vm->count_pl_tmp > MAX_PLAYERS)
		return (ERR_TO_MUCH_PLAYERS);
	if ((res = join_players(vm)) != RET_OK)
		return (res);
	if ((res = check_order(vm->players, vm->count_players)) != RET_OK)
		return (res);
	return (RET_OK);
}
