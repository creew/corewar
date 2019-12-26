/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:41:36 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_each_word(char const *s, char dem, int num)
{
	int				i;
	int				g;
	int				j;

	g = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0' && g < num)
	{
		if (s[i] != dem)
		{
			j = 0;
			while (s[i] != dem && s[i] != '\0')
			{
				i++;
				j++;
			}
			g++;
		}
		i++;
	}
	return (j);
}

static char const	*ft_p_word(char const *s, char dem, int num)
{
	int				i;
	int				g;

	i = 0;
	g = 0;
	while (s[i] != '\0')
	{
		if (s[i] != dem)
		{
			g++;
			if (g == num)
				return (s + i);
			while (s[i] != dem && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (s + i);
}

static char			**ft_fill_arr(char const *s, char c, int words, char **arr)
{
	int				l;
	int				i;
	char			*tmp;

	i = 0;
	l = 0;
	while (l < words)
	{
		tmp = (char *)ft_p_word(s, c, l + 1);
		while (i < ft_each_word(s, c, l + 1))
		{
			arr[l][i] = tmp[i];
			i++;
		}
		arr[l][i] = '\0';
		l++;
		i = 0;
	}
	return (arr);
}

static char			**ft_free(char **arr, int i)
{
	while (arr[i--])
		free(arr[i]);
	free(arr);
	return (arr);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**arr;
	int				l;
	int				words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	l = -1;
	if (!(arr = (char**)malloc(sizeof(char *) * words + 1)))
		return (NULL);
	arr[words] = 0;
	if (ft_count_words(s, c) == 0)
	{
		arr[0] = NULL;
		return (arr);
	}
	while (++l < words)
	{
		if (!(arr[l] = (char *)malloc(sizeof(char) *
		ft_each_word(s, c, l + 1) + 1)))
			return (ft_free(arr, l));
	}
	return (ft_fill_arr(s, c, words, arr));
}
