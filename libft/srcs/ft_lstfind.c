/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:56:52 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/07 18:23:37 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *alst, void *cmp, int (*f)(t_list *, void *))
{
	while (alst)
	{
		if (f(alst, cmp))
			return (alst);
		alst = alst->next;
	}
	return (NULL);
}
