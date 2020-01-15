/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ldi_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:32:20 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:32:20 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_ldi_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long		val1;
	long		val2;
	t_ulong		val;

	val1 = get_reg_dir_ind_arg(pr, run, A1);
	val2 = get_reg_dir_arg(pr, run, A2);
	val = read_be_map(vm->field, pr->pc + (val1 + val2) % IDX_MOD, DIR_SIZE,
		SIGNED);
	write_varlen_be(pr->regs[run->args[A3]], val, DIR_SIZE);
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
	{
		ft_printf("P% 5d | ldi %ld %ld r%ld\n", pr->id,
			val1, val2, run->args[A3] + 1);
		ft_printf("       | -> load from %ld + %ld = %ld (with pc and mod %ld)"
			"\n", val1, val2, val1 + val2, pr->pc + (val1 + val2) % IDX_MOD);
	}
}
