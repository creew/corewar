/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:28:39 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 12:55:04 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	hs_len;
	size_t	ne_len;
	size_t	pos;

	pos = 0;
	hs_len = ft_strlen(haystack);
	ne_len = ft_strlen(needle);
	if (ne_len == 0)
		return ((char *)haystack);
	while (haystack[pos] && ((pos + ne_len) <= hs_len))
	{
		if (ft_strncmp(haystack + pos, needle, ne_len) == 0)
			return (char *)(haystack + pos);
		pos++;
	}
	return (NULL);
}
