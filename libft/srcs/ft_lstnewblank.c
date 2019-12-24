/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 11:06:29 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/27 11:06:29 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnewblank(size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->next = NULL;
	lst->content_size = content_size;
	if (content_size)
	{
		lst->content = ft_memalloc(content_size);
		if (lst->content == NULL)
			ft_memdel((void **)&lst);
	}
	return (lst);
}
