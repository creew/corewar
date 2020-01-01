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

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		q;

	i = 0;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
		if (!str)
			return (NULL);
		while (s[i] != '\0' && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
			i++;
		j = ft_strlen(s) - 1;
		while (j > 0 && s[j] && (s[j] == '\n' || s[j] == '\t' || s[j] == ' '))
			j--;
		q = 0;
		while (i <= j)
			str[q++] = s[i++];
		str[q] = '\0';
		return (str);
	}
	else
		return (NULL);
}