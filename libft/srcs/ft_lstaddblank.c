/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:21:46 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/07 20:00:29 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddblank(t_list **alst, size_t content_size)
{
	t_list	*newlist;

	newlist = NULL;
	if (alst)
	{
		newlist = (t_list *)ft_memalloc(sizeof(t_list));
		if (newlist == NULL)
			return (NULL);
		newlist->content_size = content_size;
		newlist->content = ft_memalloc(content_size);
		if (newlist->content == NULL)
		{
			ft_memdel((void **)&newlist);
			return (NULL);
		}
		newlist->next = *alst;
		*alst = newlist;
	}
	return (newlist);
}
