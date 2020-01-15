/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:04:13 by eklompus          #+#    #+#             */
/*   Updated: 2019/10/06 17:04:13 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_queue_add(t_ftqueue **queue, void *data)
{
	t_ftqueue *newq;

	if (queue)
	{
		newq = ft_lstnewblank(0);
		if (newq)
		{
			newq->content = data;
			newq->next = *queue;
			*queue = newq;
			return (0);
		}
	}
	return (1);
}
