/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_comments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:56:52 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 11:56:54 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

void	delete_comment(char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i] != '\0')
				i++;
		}
		if (str[i] == '\0')
			return ;
		if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}

void	delete_comment_and_tabs(char *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
		}
		if (str[i] == '\t')
			str[i] = ' ';
		if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
		{
			str[i] = '\0';
			return ;
		}
		i++;
	}
}
