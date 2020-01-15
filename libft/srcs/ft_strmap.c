/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:36:44 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 13:05:51 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	length;
	char	*str;
	char	*ret;

	ret = NULL;
	length = 0;
	if (s && f)
	{
		length = ft_strlen(s);
		str = (char *)malloc(length + 1);
		if (str == NULL)
			return (NULL);
		ret = str;
		while (*s)
			*str++ = f(*s++);
		*str = '\0';
	}
	return (ret);
}
