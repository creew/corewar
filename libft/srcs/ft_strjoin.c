/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:05:01 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/04 12:33:06 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	length;
	size_t	length1;

	length1 = 0;
	length = 0;
	if (s1)
	{
		length1 = ft_strlen(s1);
		length += length1;
	}
	if (s2)
		length += ft_strlen(s2);
	str = ft_strnew(length);
	if (str)
	{
		if (s1)
			ft_strcpy(str, s1);
		if (s2)
			ft_strcpy(str + length1, s2);
	}
	return (str);
}
