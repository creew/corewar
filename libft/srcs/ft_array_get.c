/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:41:30 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/13 16:41:31 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_get(t_ftarray *arr, size_t index, void **data)
{
	if (index < arr->num_elems)
	{
		*data = arr->data[index];
		return (0);
	}
	return (1);
}
