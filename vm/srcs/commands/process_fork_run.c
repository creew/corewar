/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fork_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:31:59 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:31:59 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_fork_run(t_vm *vm, t_process *pr, t_runner *run)
{
	copy_process(&vm->processes_root, pr, pr->pc + run->args[A1] % IDX_MOD,
		&vm->process_count);
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | fork %ld (%ld)\n", pr->id,
			run->args[A1], pr->pc + run->args[A1] % IDX_MOD);
}
