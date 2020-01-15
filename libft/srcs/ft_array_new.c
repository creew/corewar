/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:37:48 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/17 17:37:49 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ftarray	*ft_array_new(size_t init_val)
{
	t_ftarray	*ftarray;

	ftarray = (t_ftarray *)ft_memalloc(sizeof(*ftarray));
	if (ftarray)
	{
		ft_array_init(ftarray, init_val);
	}
	return (ftarray);
}
