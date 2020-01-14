/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:09:03 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 15:09:03 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_result		check_dump(t_vm *vm, int *index, int ac, char *av[])
{
	if (*index + 1 < ac && ft_safe_atoi(av[*index + 1], &vm->dump_n) ==
		FT_ATOI_OK && vm->dump_n >= 0)
	{
		vm->do_dump = 1;
		(*index)++;
	}
	else
		return (ERR_INCORRECT_DUMPARG);
	return (RET_OK);
}

static t_result		check_order_flag(t_vm *vm, int *index, int ac, char *av[])
{
	int			res;
	t_player	*player;
	t_result	err;

	if (*index + 2 < ac && ft_safe_atoi(av[*index + 1], &res) ==
		FT_ATOI_OK && res >= 1 && res <= MAX_PLAYERS &&
		is_player_index_free(vm->players, res, sizeof(vm->players)))
	{
		if ((err = read_champ(av[*index + 2], &player, res)) == RET_OK)
		{
			vm->players[res - 1] = player;
			(*index) += 2;
			vm->count_players++;
		}
		else
			return (err);
	}
	else
		return (ERR_INCORRECT_NARG);
	return (RET_OK);
}

static t_result		check_debug(t_vm *vm, int *index, int ac, char *av[])
{
	int		res;

	vm->do_debug = 1;
	if (*index + 1 < ac && ft_safe_atoi(av[*index + 1], &res) ==
		FT_ATOI_OK && res >= 0 && res <= FT_INTMAX)
	{
		vm->debug_args = res;
		(*index)++;
	}
	else
		return (ERR_INCORRECT_DARG);
	return (RET_OK);
}

static t_result		read_arg_champ(t_vm *vm, const int *index, char *av[])
{
	int			res;
	t_player	*player;
	t_result	err;

	err = get_next_free_index(vm->players, &res, sizeof(vm->players));
	if (err != RET_OK)
		return (err);
	if ((err = read_champ(av[*index], &player, res)) != RET_OK)
		return (err);
	vm->players[res - 1] = player;
	vm->count_players++;
	return (RET_OK);
}

t_result			parse_arg(t_vm *vm, int *index, int ac, char *av[])
{
	t_result	err;

	err = RET_OK;
	if (!ft_strcmp(av[*index], "-dump"))
		err = check_dump(vm, index, ac, av);
	else if (!ft_strcmp(av[*index], "-n"))
		err = check_order_flag(vm, index, ac, av);
	else if (!ft_strcmp(av[*index], "-v"))
		vm->visualize = 1;
	else if (!ft_strcmp(av[*index], "-d"))
		err = check_debug(vm, index, ac, av);
	else if (!ft_strcmp(av[*index], "-a"))
		vm->print_aff = 1;
	else
		err = read_arg_champ(vm, index, av);
	return (err);
}
