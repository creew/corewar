/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:55:02 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 11:55:04 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

void	add_command(char *line, t_com *command)
{
	int i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0' &&
			line[i] != DIRECT_CHAR && line[i] != '-')
		i++;
	command->name = ft_strsub(line, 0, i);
}

void	add_command_with_label(char **line, t_com *command)
{
	int		n;
	char	*q;

	n = 0;
	while (**line != LABEL_CHAR)
		(*line)++;
	(*line)++;
	q = ft_strtrim(*line);
	while (q[n] != ' ' && q[n] != '\0' && q[n] != DIRECT_CHAR && q[n] != '-')
		n++;
	if (n >= 0)
		command->name = ft_strsub(q, 0, n);
	free(q);
}

void	add_label(char *line, t_com *commands)
{
	char **str;
	char *q;

	str = ft_strsplit(line, LABEL_CHAR);
	if (commands->label)
	{
		q = ft_strdup(commands->label);
		free(commands->label);
		commands->label = ft_strjoin(q, " ");
		free(q);
		q = ft_strdup(commands->label);
		free(commands->label);
		commands->label = ft_strjoin(q, str[0]);
		free(q);
	}
	else
		commands->label = ft_strdup(str[0]);
	str[0] ? free(str[0]) : 0;
	str[1] ? free(str[1]) : 0;
	(str[2] && str[1]) ? free(str[2]) : 0;
	free(str);
}

void	adding_args(char **args, t_com *commands)
{
	int i;

	i = -1;
	if (args[0])
	{
		commands->arg1 = ft_strtrim(args[0]);
		commands->count_args++;
	}
	if (args[1])
	{
		commands->arg2 = ft_strtrim(args[1]);
		commands->count_args++;
	}
	if (args[2] && args[1])
	{
		commands->arg3 = ft_strtrim(args[2]);
		commands->count_args++;
	}
	while (args[++i])
		free(args[i]);
	free(args);
}

void	end_name_or_comment(char **str, int i,
		char **line, t_ch *player, int z)
{
	char *q;

	if ((*str)[i] == '\0')
	{
		player->row++;
		free(*str);
		if (get_row(player->fd, line) > 0)
		{
			player->row++;
			z == 2 ? add_with_n_comment(player, *line, 2) :
			add_with_n_name(player, *line, 1);
		}
	}
	else if ((*str)[i] == '"')
	{
		q = ft_strjoin("\"", *str);
		clear_line(str);
		init_line(&q, str);
		while ((*str)[++i + 1] != '\0')
			(*str)[i] != ' ' ?
			ft_exit2("ожидался конец строки после \"", player->row) : 0;
		free(*str);
	}
}
