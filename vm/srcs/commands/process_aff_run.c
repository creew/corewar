/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_aff_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:31:41 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:31:45 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

void		process_aff_run(t_vm *vm, t_process *pr, t_runner *run)
{
	if (vm->print_aff)
		ft_printf("Aff: %c\n", pr->regs[run->args[A1]][REG_SIZE - 1]);
}
