/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:40:26 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_sort_int(int *arr, int arr_size)
{
	int	i;
	int	j;
	int	tmp;

	if (arr == NULL)
		return (NULL);
	tmp = 0;
	i = -1;
	j = arr_size;
	while (++i < arr_size)
	{
		while (--j)
		{
			if (arr[j] < arr[j - 1])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
		j = arr_size;
	}
	return (arr);
}
