/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lfork_run.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:32:26 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:32:26 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_lfork_run(t_vm *vm, t_process *pr, t_runner *run)
{
	copy_process(&vm->processes_root, pr, pr->pc + run->args[A1],
		&vm->process_count);
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | lfork %ld (%ld)\n", pr->id,
			run->args[A1], pr->pc + run->args[A1]);
}
