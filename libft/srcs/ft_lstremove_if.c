/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 07:26:05 by eklompus          #+#    #+#             */
/*   Updated: 2019/11/17 07:26:05 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstremove_if(t_list **root, int (*cmp)(void *, void *), void *sec)
{
	t_list	*ret;
	t_list	*lst;

	ret = NULL;
	while (*root)
	{
		lst = *root;
		if (cmp(lst->content, sec) == 0)
		{
			ret = lst;
			*root = lst->next;
			lst->next = NULL;
			break ;
		}
		root = &lst->next;
	}
	return (ret);
}
