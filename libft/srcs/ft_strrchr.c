/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:20:47 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/03 16:38:46 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	length++;
	while (length > 0)
	{
		if (s[length - 1] == c)
			return (char *)(s + length - 1);
		length--;
	}
	return (NULL);
}
