/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:11:04 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/26 16:43:23 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int					arg_type_(char *str, int i)
{
	if (str[0] == 'r')
		return (1);
	else if (str[0] == '%')
	{
		if (g_op_tab[i].is_tdir_2bytes)
			return (2);
		return (4);
	}
	else if (is_num(*str) || str[0] == ':')
		return (2);
	return (0);
}

int					label_num_com(t_main *str_asm, char *str, int len)
{
	t_com			*step;
	char			*s;
	char			*end;

	step = str_asm->start;
	len = ft_strlen(str);
	while (step)
	{
		if (step->label && str)
		{
			s = step->label;
			while ((end = ft_strchr(s, ' ')))
			{
				if (end - s == len)
					if (!ft_strncmp(s, str, len))
						return (step->num_byte_from_start);
				s = end + 1;
			}
			if (!ft_strcmp(str, s))
				return (step->num_byte_from_start);
		}
		step = step->next;
	}
	ft_exit(15);
	return (0);
}

int					f_num_zero(t_main *str_asm, char *str, t_com *commands)
{
	int				i;

	if ((str[0] == '%' && str[1] == ':') || str[0] == ':')
	{
		i = label_num_com(str_asm, str + (str[0] == ':' ? 1 : 2), 0);
		i -= commands->num_byte_from_start;
		return (i);
	}
	return (ft_atoi(is_num(*str) ? str : str + 1));
}

void				write_arg_to_file(t_main *str_asm, t_com *i_ams, int i)
{
	unsigned int	num_zero;
	int				n_byte;

	n_byte = arg_type_(i_ams->arg1, i);
	num_zero = f_num_zero(str_asm, i_ams->arg1, i_ams);
	write_to_file(str_asm, n_byte, num_zero);
	if (g_op_tab[i].args_count == 2)
	{
		n_byte = arg_type_(i_ams->arg2, i);
		num_zero = f_num_zero(str_asm, i_ams->arg2, i_ams);
		write_to_file(str_asm, n_byte, num_zero);
		return ;
	}
	else if (g_op_tab[i].args_count == 3)
	{
		n_byte = arg_type_(i_ams->arg2, i);
		num_zero = f_num_zero(str_asm, i_ams->arg2, i_ams);
		write_to_file(str_asm, n_byte, num_zero);
		n_byte = arg_type_(i_ams->arg3, i);
		num_zero = f_num_zero(str_asm, i_ams->arg3, i_ams);
		write_to_file(str_asm, n_byte, num_zero);
	}
}

void				count_byte(t_com *commands, int i)
{
	commands->num_byte = 1 + (g_op_tab[i].is_argtype ? 1 : 0)
	+ arg_type_(commands->arg1, i);
	if (commands->count_args == 2)
		commands->num_byte += arg_type_(commands->arg2, i);
	else if (commands->count_args == 3)
	{
		commands->num_byte += arg_type_(commands->arg2, i);
		commands->num_byte += arg_type_(commands->arg3, i);
	}
}
