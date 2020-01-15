/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:52:19 by eklompus          #+#    #+#             */
/*   Updated: 2019/10/05 12:54:39 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stack_pop(t_ftstack *stack, void **data)
{
	void	*d;

	if (ft_array_size(stack))
	{
		if (ft_array_get(stack, stack->num_elems - 1, &d) == 0)
		{
			stack->num_elems--;
			*data = d;
			return (0);
		}
	}
	return (1);
}
