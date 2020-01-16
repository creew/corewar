/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:04:40 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/26 16:31:57 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

unsigned int	swap_ints(unsigned int a)
{
	return ((a >> 24u & 0xFFu) | (a >> 8u & 0xFF00u) |
	((a & 0xFF00u) << 8u) | ((a & 0xFFu) << 24u));
}

/*
** 	ft_strcpy(header....		//обращаемся к имени чемпиона;
**	header.prog_size....		//количество байт кода;
**	ft_strcpy(header....		//обращаемся к комментарию чемпиона;
*/

void			champ_head(t_main *str_asm, t_ch *player)
{
	t_header	header;

	put_num_byte(str_asm);
	ft_bzero(&header, sizeof(header));
	header.magic = swap_ints(COREWAR_EXEC_MAGIC);
	ft_strcpy(header.prog_name, player->name);
	header.prog_size = swap_ints(str_asm->byte_cnt);
	ft_strcpy(header.comment, player->comment);
	write(str_asm->fd, &header, sizeof(header));
}

void			ft_initial_asm(t_main *str_asm, t_com *commands)
{
	str_asm->byte_cnt = 0;
	str_asm->start = commands;
	str_asm->neg_num_zero = 0;
}

/*
** 164.		//выводим код операции
** 167.		//считаем код типов аргументов, если есть
** 168.		//выводим код типов элементов
*/

void			kod_instr(t_com *commands, t_main *str_asm)
{
	int			i;

	i = num_struct(commands);
	if (i != -1)
	{
		count_byte(commands, i);
		write_to_file(str_asm, 1, g_op_tab[i].opcode);
		if (g_op_tab[i].is_argtype)
		{
			arg_code(commands);
			write_to_file(str_asm, 1, commands->kod_arg);
		}
		write_arg_to_file(str_asm, commands, i);
	}
}

int				is_num(char sym)
{
	return (sym == '-' || (sym >= '0' && sym <= '9'));
}
