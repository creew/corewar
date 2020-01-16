/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:23:09 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 12:23:10 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		valid_arg_dir(char *str)
{
	if (str && str[0] == DIRECT_CHAR)
	{
		str++;
		if (*str == '-')
			str++;
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
				str++;
			if (*str == '\0')
				return (1);
		}
		if (*(str) == LABEL_CHAR && str[1] != '\0' && str[1] != ' ')
			return (1);
	}
	return (0);
}

int		valid_arg_int(char *str)
{
	if (str && str[0] == LABEL_CHAR && str[1] != '\0' && str[1] != ' ')
		return (1);
	if (str && (str[0] == '-' || str[0] == '+'))
		str++;
	if (str && ft_isdigit(str[0]))
	{
		while (ft_isdigit(*str))
			str++;
		if (*str == '\0')
			return (1);
	}
	return (0);
}

int		valid_arg_reg(char *str)
{
	int n;

	if (str && str[0] == 'r')
	{
		str++;
		n = ft_atoi(str);
		if (n >= 0 && n < 100)
		{
			while (ft_isdigit(*str))
				str++;
			if (*str == '\0')
				return (1);
		}
	}
	return (0);
}

int		valid_args(t_com *commands, t_valid validator)
{
	int i;

	i = 0;
	while (i < 15 &&
			ft_strcmp(validator.can_use_command[i], commands->name) != 0)
		i++;
	if (validator.valid_com[i](commands))
		return (1);
	return (0);
}
