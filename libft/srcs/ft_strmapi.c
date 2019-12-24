/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:54:23 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 17:36:58 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*ret;
	size_t	index;

	ret = NULL;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str == NULL)
			return (NULL);
		ret = str;
		index = 0;
		while (*s)
			*str++ = f(index++, *s++);
		*str = '\0';
	}
	return (ret);
}
