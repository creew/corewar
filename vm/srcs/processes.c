/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:18:09 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 17:18:09 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	process_processes(t_vm *vm)
{
	t_process *pr;

	pr = vm->processes_root;
	while (pr)
	{
		if (pr->state == NOT_INITED)
		{



		}




	}



}