/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args_commands2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:27:54 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 12:27:55 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		valid_lld_arg(t_com *commands)
{
	if (!valid_arg_dir(commands->arg1) &&
		!valid_arg_int(commands->arg1))
		return (0);
	if (!valid_arg_reg(commands->arg2))
		return (0);
	return (1);
}

int		valid_st_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1))
		return (0);
	if (!valid_arg_reg(commands->arg2) &&
		!valid_arg_int(commands->arg2))
		return (0);
	return (1);
}

int		valid_add_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) ||
		!valid_arg_reg(commands->arg2) ||
		!valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		valid_sub_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) ||
		!valid_arg_reg(commands->arg2) ||
		!valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}

int		valid_and_arg(t_com *commands)
{
	if (!valid_arg_reg(commands->arg1) &&
		!valid_arg_int(commands->arg1) &&
		!valid_arg_dir(commands->arg1))
		return (0);
	if (!valid_arg_reg(commands->arg2) &&
		!valid_arg_int(commands->arg2) &&
		!valid_arg_dir(commands->arg2))
		return (0);
	if (!valid_arg_reg(commands->arg3))
		return (0);
	return (1);
}
