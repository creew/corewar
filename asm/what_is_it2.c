/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_it2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:41:41 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 12:41:43 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		command_is_valid(char *command, t_valid validator, int row)
{
	int i;

	i = 0;
	while (i < 16 && command)
	{
		if (ft_strcmp(command, validator.can_use_command[i]) == 0)
			return (1);
		i++;
	}
	ft_exit2(16, row);
	return (0);
}

int		l_and_c_one_rows(char *line)
{
	int i;

	i = 0;
	while (line[i] != LABEL_CHAR)
		i++;
	if (line[i + 1] && line[i + 1] != '\0')
		return (1);
	return (0);
}

int		if_the_end_file_with_out_n(char *line)
{
	char *q;

	q = ft_strtrim(line);
	clear_line(&line);
	if (q && ft_strcmp(q, "\0") == 0)
	{
		clear_line(&q);
		return (0);
	}
	clear_line(&q);
	return (1);
}
