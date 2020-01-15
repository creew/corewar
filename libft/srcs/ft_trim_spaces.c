/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:12:51 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/05 11:12:52 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_spaces(char *str)
{
	size_t	len;
	char	*r;

	r = str;
	while (ft_isspace(*str))
		str++;
	len = ft_strlen(str);
	while (ft_isspace(str[len - 1]))
		str[--len] = '\0';
	ft_memmove(r, str, len + 1);
	return (r);
}
