/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:51:37 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 16:51:38 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process		*add_process(t_process **root, t_uint id, long pc, size_t *pr_max)
{
	t_process *process = ft_memalloc(sizeof(*process));
	if (process)
	{
		while (pc < 0)
			pc += MEM_SIZE;
		process->id = (*pr_max)++;
		process->next = *root;
		process->prev = NULL;
		process->player_id = id;
		process->pc = (int)pc;
		write_varlen_be(process->regs[0], -id, REG_SIZE);
		if (*root)
			(*root)->prev = process;
		*root = process;
	}
	return (process);
}

void 			remove_process(t_process **root, t_process *pr)
{
	if (pr->prev)
		pr->prev->next = pr->next;
	if (pr->next)
		pr->next->prev = pr->prev;
	if (pr == *root)
		*root = pr->next;
	ft_memdel((void **)&pr);
}

t_process		*copy_process(t_process **root, t_process *copy,
	size_t *pr_max, long pc)
{
	t_process *process;

	process = add_process(root, copy->player_id, pc, pr_max);
	if (process)
	{
		ft_memcpy(process->regs, copy->regs, sizeof(copy->regs));
		process->carry = copy->carry;
		process->cycle_live = copy->cycle_live;
	}
	return (process);
}