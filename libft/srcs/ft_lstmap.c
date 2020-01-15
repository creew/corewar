/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:55:51 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/09 10:44:01 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	ft_memdel(&content);
	(void)(content_size);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*next;
	t_list	*res;
	t_list	*newlist;
	t_list	**newnext;
	t_list	*tmp;

	newlist = NULL;
	newnext = &newlist;
	while (lst)
	{
		next = lst->next;
		res = f(lst);
		tmp = ft_lstnew(res->content, res->content_size);
		if (tmp == NULL)
		{
			ft_lstdel(&newlist, &del);
			return (NULL);
		}
		*newnext = tmp;
		newnext = &(tmp->next);
		lst = next;
	}
	return (newlist);
}
