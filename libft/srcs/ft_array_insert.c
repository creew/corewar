/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:17:41 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/24 12:17:41 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_voidmove(void **dst, void **src, size_t size)
{
	if (dst < src)
	{
		while (size--)
			*dst++ = *src++;
	}
	else if (dst > src)
	{
		while (size--)
			dst[size] = src[size];
	}
}

int			ft_array_insert(t_ftarray *arr, void *data, size_t pos)
{
	void	**newarr;
	void	**old;

	if (pos >= arr->num_elems)
		return (ft_array_add(arr, data));
	if (arr->num_elems >= arr->max_elems)
	{
		newarr = ft_calloc(arr->max_elems + arr->init_val, sizeof(void *));
		if (!newarr)
			return (1);
		if (arr->data)
		{
			ft_voidcpy(newarr, arr->data, pos);
			ft_voidcpy(newarr + pos + 1, arr->data + pos, arr->num_elems - pos);
		}
		old = arr->data;
		arr->data = newarr;
		arr->max_elems += arr->init_val;
		ft_memdel((void **)&old);
	}
	else
		ft_voidmove(arr->data + pos + 1, arr->data + pos, arr->num_elems - pos);
	arr->data[pos] = data;
	arr->num_elems++;
	return (0);
}
