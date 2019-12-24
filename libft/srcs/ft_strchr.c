/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:10:49 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 16:39:08 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	length;
	size_t	count;

	count = 0;
	length = 0;
	while (s[length] != '\0')
		length++;
	length++;
	while (count < length)
	{
		if (s[count] == c)
			return (char *)(s + count);
		count++;
	}
	return (NULL);
}
