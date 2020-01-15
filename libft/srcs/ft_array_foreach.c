/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:25:05 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/14 17:25:06 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_foreach(t_ftarray *arr, void (*f)(void *, void *), void *param)
{
	size_t	count;

	count = 0;
	while (count < arr->num_elems)
	{
		f(arr->data[count], param);
		count++;
	}
	return (0);
}
