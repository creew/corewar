/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rvrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:38:01 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_rvrs(int *arr, int arr_size)
{
	int	tmp;
	int	i;
	int	j;

	if (arr == NULL)
		return (0);
	i = -1;
	j = arr_size;
	while (++i < --j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	return (arr);
}
