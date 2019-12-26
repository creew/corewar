/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:00:37 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fresh_str;

	j = 0;
	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fresh_str = (char *)malloc(sizeof(char) *
	((ft_strlen(s1) + ft_strlen(s2)) + 1));
	ft_bzero(fresh_str, ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (fresh_str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		fresh_str[i] = s1[i];
	while (s2[j] != '\0')
	{
		fresh_str[i] = s2[j];
		i++;
		j++;
	}
	fresh_str[i] = '\0';
	return (fresh_str);
}
