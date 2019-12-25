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

t_result	pl_add_carriage(t_player *pl, unsigned int place)
{
	t_carriage	*carriage;

	carriage = ft_memalloc(sizeof(*carriage));
	if (carriage == NULL)
		return (ERR_ENOMEM);
	carriage->pc = place;
	if (ft_array_add(&pl->carriages, carriage) != 0)
	{
		ft_memdel((void **)&carriage);
		return (ERR_ENOMEM);
	}
	return (RET_OK);
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
		pl_add_carriage(pl, start);
	}
}