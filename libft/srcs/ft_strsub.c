/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:33:10 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 13:09:11 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	str = NULL;
	if (s)
	{
		str = ft_strnew(len);
		if (str != NULL)
		{
			s += start;
			count = 0;
			while (count < len)
			{
				str[count] = s[count];
				count++;
			}
			str[count] = '\0';
		}
	}
	return (str);
}
