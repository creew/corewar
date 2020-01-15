/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:11:27 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/13 16:11:29 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_array_init(t_ftarray *ftarray, size_t init_val)
{
	if (ftarray)
	{
		if (init_val == 0)
			init_val = 64;
		ft_bzero(ftarray, sizeof(t_ftarray));
		ftarray->init_val = init_val;
		return (0);
	}
	return (1);
}
