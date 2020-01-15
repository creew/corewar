/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:46:45 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/07 19:59:57 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	length;
	char	*str;

	length = 0;
	while (s1[length] && length < n)
		length++;
	str = ft_strnew(length);
	if (str)
	{
		str[length] = 0;
		while (length > 0)
		{
			str[length - 1] = s1[length - 1];
			length--;
		}
	}
	return (str);
}
