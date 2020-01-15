/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clears.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:56:07 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 11:56:09 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

void	clear_commands(t_com **coms)
{
	t_com *q;

	if (!(*coms))
		return ;
	while (*coms && (*coms)->next)
	{
		q = *coms;
		(*coms) = (*coms)->next;
		free(q->name);
		free(q->arg2);
		free(q->arg1);
		free(q->arg3);
		free(q->label);
		free(q);
	}
	free((*coms)->name);
	free((*coms)->arg2);
	free((*coms)->label);
	free((*coms)->arg1);
	free((*coms)->arg3);
	free(*coms);
}

void	clear_line(char **str)
{
	if (str && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

void	clear_player(t_ch *player)
{
	free(player->name);
	free(player->comment);
}
