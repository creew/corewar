/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_awm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:58:10 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 11:58:12 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

void	init_validator(t_valid *validator)
{
	validator->valid_com[0] = &valid_live;
	validator->valid_com[1] = &valid_ld;
	validator->valid_com[2] = &valid_st;
	validator->valid_com[3] = &valid_add;
	validator->valid_com[4] = &valid_sub;
	validator->valid_com[5] = &valid_and;
	validator->valid_com[6] = &valid_or;
	validator->valid_com[7] = &valid_xor;
	validator->valid_com[8] = &valid_zjmp;
	validator->valid_com[9] = &valid_ldi;
	validator->valid_com[10] = &valid_sti;
	validator->valid_com[11] = &valid_fork;
	validator->valid_com[12] = &valid_lld;
	validator->valid_com[13] = &valid_lldi;
	validator->valid_com[14] = &valid_lfork;
	validator->valid_com[15] = &valid_aff;
	init_command(validator);
}

void	init_command(t_valid *validator)
{
	ft_strcpy(validator->can_use_command[0], "live");
	ft_strcpy(validator->can_use_command[1], "ld");
	ft_strcpy(validator->can_use_command[2], "st");
	ft_strcpy(validator->can_use_command[3], "add");
	ft_strcpy(validator->can_use_command[4], "sub");
	ft_strcpy(validator->can_use_command[5], "and");
	ft_strcpy(validator->can_use_command[6], "or");
	ft_strcpy(validator->can_use_command[7], "xor");
	ft_strcpy(validator->can_use_command[8], "zjmp");
	ft_strcpy(validator->can_use_command[9], "ldi");
	ft_strcpy(validator->can_use_command[10], "sti");
	ft_strcpy(validator->can_use_command[11], "fork");
	ft_strcpy(validator->can_use_command[12], "lld");
	ft_strcpy(validator->can_use_command[13], "lldi");
	ft_strcpy(validator->can_use_command[14], "lfork");
	ft_strcpy(validator->can_use_command[15], "aff");
}

t_com	*lst_create_commands(void)
{
	t_com *commands;

	commands = (t_com *)malloc(sizeof(t_com));
	commands->arg1 = NULL;
	commands->arg2 = NULL;
	commands->arg3 = NULL;
	commands->label = NULL;
	commands->name = NULL;
	commands->next = NULL;
	commands->kod_arg = 0;
	commands->num_byte_from_start = 0;
	commands->num_byte = 0;
	commands->row = 0;
	commands->count_args = 0;
	return (commands);
}

void	init_line(char **line, char **q)
{
	if (!(*line))
	{
		*q = NULL;
		return ;
	}
	delete_comment(*line);
	ft_delete_tabs(*line);
	*q = ft_strtrim(*line);
	clear_line(line);
	*line = *q;
}

void	lst_create_player(char *str, t_ch *player)
{
	player->name = NULL;
	player->comment = NULL;
	player->fd = open(str, O_RDONLY);
	player->row = 0;
}
