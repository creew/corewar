/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:42:22 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 16:42:22 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		start_pause(t_vm *vm)
{
	if (vm->state == PAUSED)
		vm->state = RUNNING;
	else if (vm->state == RUNNING)
		vm->state = PAUSED;
}

void		dec_values(t_vm *vm)
{
	size_t			i;
	t_fieldelem		*elems;

	elems = vm->field;
	i = -1;
	while (++i < sizeof(vm->field) / sizeof(vm->field[0]))
	{
		if (elems[i].fresh)
			elems[i].fresh--;
		if (elems[i].live)
			elems[i].live--;
	}
}

void		inc_counter(t_vm *vm)
{
	vm->cycles++;
	if (vm->visualize)
		dec_values(vm);
}
