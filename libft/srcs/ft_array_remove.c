/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:46:17 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/14 11:46:18 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_remove(t_ftarray *arr, size_t index, void (*f)(void *))
{
	void	*data;

	if (index < arr->num_elems)
	{
		data = arr->data[index];
		arr->num_elems--;
		if (arr->num_elems - index > 0)
		{
			ft_voidcpy(arr->data + index, arr->data + index + 1,
				arr->num_elems - index);
		}
		if (f)
			f(data);
		return (0);
	}
	return (1);
}
