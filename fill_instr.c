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

void				arg_code_byte(t_com *i_ams, char c, int num)
{
	if (c == 'r')
		i_ams->kod_arg |= (REG_CODE << num);
	else if (c == '%')
		i_ams->kod_arg |= (DIR_CODE << num);
	else if (c == '-')
		i_ams->kod_arg |= (IND_CODE << num);
}

void				write_to_file(t_main *str_asm, int num, int int_c)
{
	unsigned char	c;
	unsigned char	b;

	b = 0;
	c = int_c;
	if (num == 2)
	{
		if (str_asm->neg_num_zero)
			b = 255;
		write(str_asm->fd, &b, 1);
		write(str_asm->fd, &c, 1);
		if (str_asm->neg_num_zero)
			str_asm->neg_num_zero = 0;
		return ;
	}
	write(str_asm->fd, &c, num);
}

void				arg_code(t_com *i_ams)
{
	i_ams->kod_arg = 0;
	arg_code_byte(i_ams, i_ams->arg1[0], 6);
	if (i_ams->count_args == 2)
		arg_code_byte(i_ams, i_ams->arg2[0], 4);
	else if (i_ams->count_args == 3)
	{
		arg_code_byte(i_ams, i_ams->arg2[0], 4);
		arg_code_byte(i_ams, i_ams->arg3[0], 2);
	}
	else if (i_ams->count_args < 0 || i_ams->count_args > 3)
		ft_exit(4);
}

int					arg_type_(char *str, int i)
{
	if (str[0] == 'r')
		return (1);
	else if (str[0] == '%')
	{
		if (op_tab[i].is_tdir_2bytes)
			return (2);
		return (4);
	}
	else if (str[0] == '-')
		return (2);
	return (0);
}

int					label_num_com(t_main *str_asm, char *str)
{
	t_com			*step;

	step = str_asm->start;
	while (step->next)
	{
		if (step->label && str)
			if (!ft_strcmp(str, step->label))
				return (step->num_byte_from_start);
		step = step->next;
	}
	return (77);
}

int					f_num_zero(t_main *str_asm, char *str, t_com *commands)
{
	int				i;
	unsigned char	b;

	if (str[1] == ':')
	{
		i = label_num_com(str_asm, str + 2);
		i -= commands->num_byte_from_start;
		b = i;
		if (i < 0)
		{
			b = i * (-1);
			b = ~b;
			str_asm->neg_num_zero = 1;
			return (b + 1);
		}
		return (b);
	}
	return (ft_atoi(str + 1));
}

void				write_arg_to_file(t_main *str_asm, t_com *i_ams, int i)
{
	unsigned int	num_zero;
	int				n_byte;

	n_byte = arg_type_(i_ams->arg1, i);
	num_zero = f_num_zero(str_asm, i_ams->arg1, i_ams);
	write_to_file(str_asm, n_byte, num_zero);
	if (op_tab[i].args_count == 2)
	{
		n_byte = arg_type_(i_ams->arg2, i);
		num_zero = f_num_zero(str_asm, i_ams->arg2, i_ams);
		write_to_file(str_asm, n_byte, num_zero);
		return ;
	}
	else if (op_tab[i].args_count == 3)
	{
		n_byte = arg_type_(i_ams->arg2, i);
		num_zero = f_num_zero(str_asm, i_ams->arg2, i_ams);
		write_to_file(str_asm, n_byte, num_zero);
		n_byte = arg_type_(i_ams->arg3, i);
		num_zero = f_num_zero(str_asm, i_ams->arg3, i_ams);
		write_to_file(str_asm, n_byte, num_zero);
	}
}

void	count_byte(t_com *commands, int i)
{
	commands->num_byte = 1 + (op_tab[i].is_argtype ? 1 : 0)
	+ arg_type_(commands->arg1, i);
	if (commands->count_args == 2)
		commands->num_byte += arg_type_(commands->arg2, i);
	else if (commands->count_args == 3)
	{
		commands->num_byte += arg_type_(commands->arg2, i);
		commands->num_byte += arg_type_(commands->arg3, i);
	}
}

/*
** 164.		//выводим код операции
** 167.		//считаем код типов аргументов, если есть
** 168.		//выводим код типов элементов
*/

void	kod_instr(t_com *commands, t_main *str_asm)
{
	int i;

	i = 0;
	while (ft_strcmp(commands->name, op_tab[i].name))
		i++;
	count_byte(commands, i);
	write_to_file(str_asm, 1, op_tab[i].opcode);
	if (op_tab[i].is_argtype)
	{
		arg_code(commands);
		write_to_file(str_asm, 1, commands->kod_arg);
	}
	write_arg_to_file(str_asm, commands, i);
}
