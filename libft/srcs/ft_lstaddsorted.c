/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddsorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <eklompus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 10:50:05 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/27 10:58:10 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddsorted(t_list **root, t_list *node, void *param,
	int (*cmp)(t_list *, t_list *, void *))
{
	t_list **prev;
	t_list *lst;

	if (!root || !node || !cmp)
		return ;
	lst = *root;
	prev = root;
	while (lst)
	{
		if (cmp(lst, node, param) > 0)
			break ;
		prev = &(lst->next);
		lst = lst->next;
	}
	node->next = lst;
	*prev = node;
}
