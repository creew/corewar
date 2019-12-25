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

void 		inc_counter(t_vm *vm)
{
	int i;

	if (vm->started)
	{
		vm->cycles++;
		i = 0;
		while (i < vm->delay)
			i++;
	}
}