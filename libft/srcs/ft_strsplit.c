/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:07:21 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/27 11:43:24 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	fill_arr(char **strarr, int count, char const *s, char *sc)
{
	size_t		len;

	if (strarr == NULL)
		return (0);
	len = sc == NULL ? ft_strlen(s) : (size_t)(sc - s);
	strarr[count] = ft_strnew(len);
	if (strarr[count] == NULL)
	{
		while (count > 0)
		{
			ft_strdel(&strarr[count - 1]);
			count--;
		}
		return (-1);
	}
	ft_strncpy(strarr[count], s, len);
	return (0);
}

static int	count_words(char **strarr, char const *s, char c)
{
	char	*sc;
	int		count;
	int		res;

	count = 0;
	while (*s)
	{
		sc = ft_strchr(s, c);
		if (sc != s)
		{
			res = fill_arr(strarr, count, s, sc);
			if (res < 0)
				return (res);
			count++;
		}
		if (sc == NULL)
			break ;
		s = sc + 1;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**strarr;
	int		res;

	strarr = NULL;
	if (s)
	{
		count = count_words(NULL, s, c);
		strarr = (char **)ft_memalloc(sizeof(char *) * (count + 1));
		if (strarr != NULL)
		{
			strarr[count] = NULL;
			res = count_words(strarr, s, c);
			if (res < 0)
				ft_memdel((void **)&strarr);
		}
	}
	return (strarr);
}
