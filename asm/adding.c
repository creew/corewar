/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:52:28 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 11:52:29 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

void	add_comment(char *str, t_ch *player)
{
	int i;

	i = 1;
	if (player->comment != NULL)
		ft_exit2(9, player->row);
	while (*str != '"' && *str != '\0')
		str++;
	if (*str == '\0')
		ft_exit2(10, player->row);
	while (str[i] != '"' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		add_with_n_comment(player, ft_strdup(1 + str), 2);
		if (ft_strlen(player->comment) > COMMENT_LENGTH)
			ft_exit2(11, player->row);
		return ;
	}
	if (str[i + 1] && str[i + 1] != '\0')
		ft_exit2(12, player->row);
	player->comment = ft_strsub(str, 1, i - 1);
	if (ft_strlen(player->comment) > COMMENT_LENGTH)
		ft_exit2(13, player->row);
}

void	add_with_n_comment(t_ch *player, char *str, int z)
{
	int		i;
	char	*line;
	char	*s;

	line = NULL;
	s = NULL;
	i = 0;
	if (*str != '"')
	{
		while (str[i] != '\0' && str[i] != '"')
			i++;
		line = (str[i] == '\0') ?
				ft_strjoin(str, "\n") :
				ft_strsub(str, 0, i);
		if (player->comment)
		{
			s = ft_strdup(player->comment);
			free(player->comment);
		}
		player->comment = s ? ft_strjoin(s, line) : ft_strdup(line);
		s ? free(s) : 0;
		free(line);
	}
	end_name_or_comment(&str, i, player, z);
}

void	add_name(char *str, t_ch *player)
{
	int i;

	i = 1;
	if (player->name != NULL)
		ft_exit2(5, player->row);
	while (*str != '"' && *str != '\0')
		str++;
	if (*str == '\0')
		ft_exit2(6, player->row);
	while (str[i] != '"' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		add_with_n_name(player, ft_strdup(1 + str), 1);
		if (ft_strlen(player->name) > PROG_NAME_LENGTH)
			ft_exit2(7, player->row);
		return ;
	}
	(str[i + 1] && str[i + 1] != '\0') ?
			ft_exit2(8, player->row) : 0;
	player->name = ft_strsub(str, 1, i - 1);
	if (ft_strlen(player->name) > PROG_NAME_LENGTH)
		ft_exit2(7, player->row);
}

void	add_with_n_name(t_ch *player, char *str, int z)
{
	int		i;
	char	*line;
	char	*s;

	line = NULL;
	s = NULL;
	i = 0;
	if (*str != '"')
	{
		while (str[i] != '\0' && str[i] != '"')
			i++;
		line = (str[i] == '\0') ?
				ft_strjoin(str, "\n") :
				ft_strsub(str, 0, i);
		if (player->name)
		{
			s = ft_strdup(player->name);
			free(player->name);
		}
		player->name = s ? ft_strjoin(s, line) : ft_strdup(line);
		s ? free(s) : 0;
		free(line);
	}
	end_name_or_comment(&str, i, player, z);
}

void	add_args(char **line, t_com *commands, t_ch player)
{
	char	**args;
	int		i;
	char	*s;
	char	*q;

	s = ft_strtrim(*line);
	q = s;
	i = 0;
	while (*s && *s != ' ' && *s != DIRECT_CHAR && *s != '-')
		s++;
	while (s[i] && s[i] != '\0')
		i++;
	if (s[i - 1] && s[i - 1] == SEPARATOR_CHAR)
		ft_exit2(17, player.row);
	args = ft_strsplit(s, SEPARATOR_CHAR);
	adding_args(args, commands);
	free(q);
}
