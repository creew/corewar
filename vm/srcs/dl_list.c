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

t_process *add_process(t_process **root, t_uint id, t_uint pc)
{
	t_process *process = ft_memalloc(sizeof(*process));
	if (process)
	{
		process->next = *root;
		process->prev = NULL;
		process->id = id;
		process->pc = pc;
		write_varlen_be(process->regs[0], id, REG_SIZE);
		*root = process;
	}
	return (process);
}
