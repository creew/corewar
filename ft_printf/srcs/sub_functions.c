/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:00:49 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/26 10:23:15 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*pf_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	unsigned char	*arr;
	size_t			count;

	count = 0;
	ch = (unsigned char)c;
	arr = (unsigned char *)b;
	while (count < len)
		arr[count++] = ch;
	return (b);
}

char	*pf_strchr(const char *s, int c)
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

size_t	pf_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int		pf_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}
