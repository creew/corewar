/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:47:18 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sp(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	return (0);
}

static int	ft_total_sp(char const *str)
{
	int		i;
	int		j;

	j = ft_strlen(str) - 1;
	i = 0;
	while (ft_is_sp(str[i]))
		i++;
	if (i - 1 == j)
		return (i);
	while (j != 0)
	{
		if (ft_is_sp(str[j]) == 0)
			return (i);
		i++;
		j--;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = -1;
	if (s == NULL)
		return (NULL);
	if (!(new_str =
		(char *)malloc(sizeof(char) * (ft_strlen(s) - ft_total_sp(s)) + 1)))
		return (NULL);
	ft_memset(new_str, '\0', ft_strlen(s) - ft_total_sp(s) + 1);
	while (s[i] != '\0')
	{
		if (ft_is_sp(s[i]) == 0)
		{
			while (++j < ((int)ft_strlen(s) - ft_total_sp(s)))
			{
				new_str[j] = s[i];
				i++;
			}
		}
		i++;
	}
	return (new_str);
}
