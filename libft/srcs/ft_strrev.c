/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:10:00 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 16:14:51 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	index;
	char	c;

	if (str)
	{
		index = 0;
		len = ft_strlen(str);
		while (index < (len / 2))
		{
			c = str[index];
			str[index] = str[len - index - 1];
			str[len - index - 1] = c;
			index++;
		}
	}
	return (str);
}
