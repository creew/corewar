/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_zjmp_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:33:33 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:33:34 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_zjmp_run(t_vm *vm, t_process *pr, t_runner *run)
{
	int		diff;

	diff = (int)(run->args[A1] % IDX_MOD);
	if (pr->carry)
	{
		pr->pc += diff;
		while (pr->pc < 0)
			pr->pc += MEM_SIZE;
		run->skip = 0;
	}
	if (vm->debug_args & VERB_SHOW_OPERATIONS)
		ft_printf("P% 5d | zjmp %ld %s\n",
			pr->id, run->args[A1], pr->carry ? "OK" : "FAILED");
}
