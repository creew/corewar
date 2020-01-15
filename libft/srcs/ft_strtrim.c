/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:34:18 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/08 13:13:22 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	const	*skip_spaces(char const *s)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	return (s);
}

static char	const	*skip_rspaces(char const *s)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0 &&
			(s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	return (s + len);
}

char				*ft_strtrim(char const *s)
{
	char		*str;
	char const	*s1;
	char const	*s2;

	str = NULL;
	if (s)
	{
		s1 = skip_spaces(s);
		s2 = skip_rspaces(s1);
		str = ft_strnew(s2 - s1);
		if (str)
			ft_strncpy(str, s1, s2 - s1);
	}
	return (str);
}
