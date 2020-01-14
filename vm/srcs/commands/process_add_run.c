/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_add_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:31:34 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:31:35 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_add_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	res;

	res = read_varlen_be(pr->regs[run->args[A1]], sizeof(pr->regs[0]), SIGNED);
	res += read_varlen_be(pr->regs[run->args[A2]], sizeof(pr->regs[0]), SIGNED);
	write_varlen_be(pr->regs[run->args[A3]], res, sizeof(pr->regs[0]));
	pr->carry = res == 0;
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | add r%ld r%ld r%ld\n", pr->id,
				run->args[A1] + 1, run->args[A2] + 1, run->args[A3] + 1);
}
