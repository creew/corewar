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
	vm->started = !vm->started;
}

void		dec_values(t_vm *vm)
{
	int				i;
	t_fieldelem		*elems;

	elems = vm->field;
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (elems[i].fresh)
			elems[i].fresh--;
		if (elems[i].live)
			elems[i].live--;
	}
}

void 		inc_counter(t_vm *vm)
{
	vm->cycles++;
	if (vm->visualize)
	{
		dec_values(vm);
	}
}