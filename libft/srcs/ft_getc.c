/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:08:35 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/23 16:05:34 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_getc(int fd)
{
	char	c;
	int		ret;

	ret = read(fd, &c, 1);
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (FT_EOF);
	return (c);
}
