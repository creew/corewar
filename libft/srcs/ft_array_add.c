/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:16:20 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/13 16:16:20 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_array_add(t_ftarray *arr, void *data)
{
	void	**newarr;
	void	**old;

	if (arr->num_elems >= arr->max_elems)
	{
		newarr = ft_calloc(arr->max_elems + arr->init_val, sizeof(void *));
		if (!newarr)
			return (1);
		if (arr->data)
			ft_voidcpy(newarr, arr->data, arr->max_elems);
		old = arr->data;
		arr->data = newarr;
		arr->max_elems += arr->init_val;
		ft_memdel((void **)&old);
	}
	arr->data[arr->num_elems++] = data;
	return (0);
}
