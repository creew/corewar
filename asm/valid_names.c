/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:34:22 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 12:34:23 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

void			exist_label(char *str, int flag[3], t_com *q, int i)
{
	if (str && str[0] == '%' && str[1] == ':')
	{
		flag[i] == 0 ? flag[i] = 1 : 0;
		if (flag[i] == 1 && label_is(str + 2, q))
			flag[i] = 2;
	}
	if (str && str[0] == ':')
	{
		flag[i] == 0 ? flag[i] = 1 : 0;
		if (flag[i] == 1 && label_is(str + 1, q))
			flag[i] = 2;
	}
}

static void		init_variables(int *row, int flag[3],
		t_com **q, t_com *head)
{
	(*row)++;
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	*q = head;
}

static void		init_variables2(int *row, t_com **com, t_com *head)
{
	*row = 0;
	*com = head;
}

int				valid_labeles(t_com *head)
{
	t_com	*q;
	t_com	*com;
	int		flag[3];
	int		row;

	init_variables2(&row, &com, head);
	while (com)
	{
		init_variables(&row, flag, &q, head);
		while (q)
		{
			exist_label(com->arg1, flag, q, 0);
			exist_label(com->arg2, flag, q, 1);
			exist_label(com->arg3, flag, q, 2);
			if (!q->next)
				break ;
			q = q->next;
		}
		if (flag[0] == 1 || flag[1] == 1 || flag[2] == 1)
			return (com->row);
		if (!com->next)
			break ;
		com = com->next;
	}
	return (-1);
}

int				valid_label(char *label)
{
	int i;
	int j;

	i = 0;
	while (label[i] != '\0')
	{
		j = 0;
		while (LABEL_CHARS[j] != '\0' &&
				label[i] != LABEL_CHARS[j] &&
				label[i] != ' ' &&
				label[i] != DIRECT_CHAR)
			j++;
		if (LABEL_CHARS[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
