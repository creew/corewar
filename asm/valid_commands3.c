/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_commands3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:30:52 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 12:30:53 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		valid_ld(t_com *commands)
{
	if (commands->count_args != 2)
		return (0);
	return (valid_ld_arg(commands));
}

int		valid_st(t_com *commands)
{
	if (commands->count_args != 2)
		return (0);
	return (valid_st_arg(commands));
}

int		valid_add(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (valid_add_arg(commands));
}

int		valid_sub(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (valid_sub_arg(commands));
}

int		valid_and(t_com *commands)
{
	if (commands->count_args != 3)
		return (0);
	return (valid_and_arg(commands));
}
