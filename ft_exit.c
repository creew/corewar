/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:44:49 by rmarni            #+#    #+#             */
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

void				errors_code(int num)
{
	char			*tmp;

	if (num == 1)
		tmp = "Missing or error at champion .name\n";
	else if (num == 2)
		tmp = "Missing or error at champion .comment\n";
	else if (num == 3)
		tmp = "Please provide the valide file with .s extention\n";
	else if (num == 4)
		tmp = "Wrong num of argument\n";
	else if (num == 0)
		tmp = "Please upload valide .s file\n";
	printf("%s", tmp);
}

void				ft_exit(int num)
{
	ft_printf(RED("ERROR: "));
	errors_code(num);
	exit(0);
}

