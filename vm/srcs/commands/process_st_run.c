/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_st_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:33:04 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:33:05 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_st_run(t_vm *vm, t_process *pr, t_runner *run)
{
	if (run->types[A2] == REG_CODE)
	{
		ft_memcpy(pr->regs[run->args[A2]], pr->regs[run->args[A1]],
			sizeof(pr->regs[0]));
		if (vm->debug_args & VERB_SHOW_OPERATIONS)
			ft_printf("P% 5d | st r%ld %ld\n", pr->id,
				run->args[A1] + 1, run->args[A2] + 1);
	}
	else
	{
		set_field_vals(vm->field, pr->pc + (run->args[A2] % IDX_MOD),
			pr, run->args[A1]);
		if (vm->debug_args & VERB_SHOW_OPERATIONS)
			ft_printf("P% 5d | st r%ld %ld\n", pr->id,
				run->args[A1] + 1, run->args[A2]);
	}
}
