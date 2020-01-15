/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:52:13 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 12:02:19 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*str;

	length = 0;
	while (s1[length])
		length++;
	str = (char *)malloc(length + 1);
	if (str == NULL)
		return (NULL);
	str[length] = 0;
	while (length > 0)
	{
		str[length - 1] = s1[length - 1];
		length--;
	}
	return (str);
}
