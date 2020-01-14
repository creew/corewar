/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:40:42 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 12:40:45 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		is_command(char *line, t_valid validator, int row)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i] != ' ' &&
			line[i] != '\0' &&
			line[i] != DIRECT_CHAR &&
			line[i] != '-')
		i++;
	str = ft_strsub(line, 0, i);
	if (str && command_is_valid(str, validator, row))
	{
		free(str);
		return (1);
	}
	if (str)
		free(str);
	return (0);
}

int		it_s_label(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != ' ' &&
			line[i] != '\t' &&
			line[i] != '\n' &&
			line[i] != '\0' &&
			line[i] != DIRECT_CHAR)
	{
		if (line[i] == LABEL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

int		label_is(char *str, t_com *commands)
{
	if (commands->label && ft_is_strstr(commands->label, str))
		return (1);
	return (0);
}

int		it_s_comment(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	str = ft_strsub(line, 0, i);
	if (ft_strcmp(str, COMMENT_CMD_STRING) == 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int		it_s_name(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0' && line[i] != '"')
		i++;
	str = ft_strsub(line, 0, i);
	if (ft_strcmp(str, NAME_CMD_STRING) == 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}
