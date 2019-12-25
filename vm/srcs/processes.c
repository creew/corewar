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

extern t_op    op_tab[17];


void 	process_live(t_vm *vm, t_process *pr)
{


}

void 	process_ld(t_vm *vm, t_process *pr)
{


}

void 	process_st(t_vm *vm, t_process *pr)
{


}

void 	process_add(t_vm *vm, t_process *pr)
{


}

void 	process_sub(t_vm *vm, t_process *pr)
{


}

void 	process_and(t_vm *vm, t_process *pr)
{


}

void 	process_or(t_vm *vm, t_process *pr)
{


}

void 	process_xor(t_vm *vm, t_process *pr)
{


}

void 	process_zjmp(t_vm *vm, t_process *pr)
{


}

void 	process_ldi(t_vm *vm, t_process *pr)
{


}

void 	process_sti(t_vm *vm, t_process *pr)
{


}

void 	process_fork(t_vm *vm, t_process *pr)
{


}

void 	process_lld(t_vm *vm, t_process *pr)
{


}

void 	process_lldi(t_vm *vm, t_process *pr)
{


}

void 	process_lfork(t_vm *vm, t_process *pr)
{


}

void 	process_aff(t_vm *vm, t_process *pr)
{


}

void (*g_asm_funcs[])(t_vm *vm, t_process *pr) = {
	process_live,
	process_ld,
	process_st,
	process_add,
	process_sub,
	process_and,
	process_or,
	process_xor,
	process_zjmp,
	process_ldi,
	process_sti,
	process_fork,
	process_lld,
	process_lldi,
	process_lfork,
	process_aff
};

t_op	*get_by_id(t_uint id)
{
	t_uint	i;

	i = -1;
	while (op_tab[++i].name)
	{
		if (op_tab[i].opcode == id)
			return (op_tab +i);

	}
	return (NULL);
}

void	process_waiting(t_vm *vm, t_process *pr)
{
	if (pr->wait > 0)
		pr->wait--;
	if (pr->wait == 0)
	{
		pr->pc++;
		if (pr->opcode >= 1 && pr->opcode <= 16)
			g_asm_funcs[pr->opcode - 1](vm, pr);
		pr->pc %= MEM_SIZE;
	}
}

void	process_processes(t_vm *vm)
{
	t_process	*pr;
	t_uchar		id;
	t_op		*op;

	pr = vm->processes_root;
	while (pr)
	{
		if (pr->state == NOT_INITED)
		{
			id = vm->field[pr->pc & 0xFFu];
			if ((op = get_by_id(id)) != NULL)
			{
				pr->wait = op->wait;
				pr->state = WAITING;
			}
			pr->opcode = id;
		}
		if (pr->state == WAITING)
			process_waiting(vm, pr);
		pr = pr->next;
	}
}