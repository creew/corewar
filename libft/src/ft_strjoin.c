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
	char	*str;
	int		j;

	if (s1 && s2)
	{
		str = (char *)
				malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		i = 0;
		if (!str)
			return (NULL);
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
