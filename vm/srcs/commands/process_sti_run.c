/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sti_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:33:09 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:33:10 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_sti_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	val2;
	long	val3;

	val2 = get_reg_dir_ind_arg(pr, run, A2);
	val3 = get_reg_dir_arg(pr, run, A3);
	set_field_vals(vm->field, pr->pc + (val2 + val3) % IDX_MOD,
		pr, run->args[A1]);
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
	{
		ft_printf("P% 5d | sti r%ld %ld %ld\n", pr->id,
			run->args[A1] + 1, val2, val3);
		ft_printf("       | -> store to %ld + %ld = %ld (with pc and mod %ld)"
			"\n", val2, val3, val2 + val3, pr->pc + (val2 + val3) % IDX_MOD);
	}
}
