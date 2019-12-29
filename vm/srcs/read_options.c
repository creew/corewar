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

static int			is_player_index_free(t_arrplayers *arr, int player_id)
{
	size_t		index;
	t_player	*pl;

	index = -1;
	while (ft_array_get(arr, ++index, (void **)&pl) == 0)
	{
		if (pl->player_id == player_id)
			return (0);
	}
	return (1);
}

static t_result		parse_arg(t_vm *vm, int *index, int ac, char *av[])
{
	int			res;
	t_player	*player;
	t_result	err;

	if (!ft_strcmp(av[*index], "-dump"))
	{
		if (*index + 1 < ac && ft_safe_atoi(av[*index + 1], &vm->dump_n) == FT_ATOI_OK && vm->dump_n >= 0)
		{
			vm->do_dump = 1;
			(*index)++;
		}
		else
			return (ERR_INCORRECT_DUMPARG);
	}
	else if (!ft_strcmp(av[*index], "-n"))
	{
		if (*index + 2 < ac && ft_safe_atoi(av[*index + 1], &res) == FT_ATOI_OK && res >= 1 && res <= MAX_PLAYERS && is_player_index_free(&vm->players, res))
		{
			if ((err = read_champ(av[*index + 2], &player)) == RET_OK)
			{
				ft_array_add(&vm->players, player);
				(*index)++;
			}
			else
				return (err);
		}
		else
			 return (ERR_INCORRECT_NARG);
	}
	else
	{
		if ((err = read_champ(av[*index], &player)) == RET_OK)
			ft_array_add(&vm->players, player);
		else
			return (err);
	}
}

t_result			read_option(t_vm *vm, int ac, char *av[])
{
	int		count;

	if (ac < 2)
		return (ERR_NO_ARGUMENTS);
	count = 1;
	while (count < ac)
		count = parse_arg(vm, &count, ac, av);
	if (ft_array_size(&vm->players) < 2)
		return (ERR_TO_LITTLE_PLAYERS);
	return (RET_OK);
}