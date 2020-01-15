/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_poll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 17:09:26 by eklompus          #+#    #+#             */
/*   Updated: 2019/10/06 17:36:48 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delone(void *data, size_t content_size)
{
	(void)content_size;
	(void)data;
}

int			ft_queue_poll(t_ftqueue **queue, void **data)
{
	while (*queue)
	{
		if ((*queue)->next == 0)
		{
			*data = (*queue)->content;
			ft_lstdelone(queue, delone);
			return (0);
		}
		queue = &((*queue)->next);
	}
	return (1);
}
