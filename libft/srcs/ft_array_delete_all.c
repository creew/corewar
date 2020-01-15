/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_delete_all.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:43:34 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/17 17:43:35 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_delete_all(t_ftarray **arr, void (*f)(void *))
{
	t_ftarray	*ftarray;

	ftarray = *arr;
	if (ftarray)
	{
		if (f)
		{
			while (ftarray->num_elems)
			{
				f(ftarray->data[ftarray->num_elems - 1]);
				ftarray->num_elems--;
			}
		}
		ft_memdel((void **)&ftarray->data);
		ft_memdel((void **)arr);
	}
}
