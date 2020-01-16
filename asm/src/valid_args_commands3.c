/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args_commands3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:28:35 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 12:28:36 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		valid_live(t_com *commands)
{
	if (commands->count_args != 1)
		return (0);
	return (valid_arg_dir(commands->arg1));
}

int		valid_ld_arg(t_com *commands)
{
	if (!valid_arg_dir(commands->arg1) &&
		!valid_arg_int(commands->arg1))
		return (0);
	if (!valid_arg_reg(commands->arg2))
		return (0);
	return (1);
}
