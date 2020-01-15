/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:20:59 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/04 16:21:00 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	const char	*set;

	while (*s)
	{
		set = charset;
		while (*set)
		{
			if (*set == *s)
				return ((char *)s);
			set++;
		}
		s++;
	}
	return (NULL);
}
