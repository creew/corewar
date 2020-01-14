/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ld_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:32:13 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:32:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_ld_run(t_vm *vm, t_process *pr, t_runner *run)
{
	long	a1;

	a1 = get_dir_ind_arg(pr, run, A1);
	write_varlen_be(pr->regs[run->args[A2]], a1, sizeof(pr->regs[0]));
	pr->carry = a1 == 0;
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | ld %ld r%ld\n", pr->id, a1, run->args[A2] + 1);
}
