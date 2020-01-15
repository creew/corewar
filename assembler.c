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

void		ft_check_extention(char *str, t_main *str_asm)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 's' && str[i - 2] != '.')
		ft_exit(3);
	tmp = ft_strjoin(str, "or");
	tmp[i - 1] = 'c';
	str_asm->name = tmp;
	str_asm->fd = creat(str_asm->name, 0666);
	free(tmp);
}

int			num_struct(t_com *commands)
{
	int		i;

	i = 0;
	while (ft_strcmp(commands->name, op_tab[i].name))
		i++;
	return (i);
}

void		put_num_byte(t_main *str_asm)
{
	t_com	*step;
	int		current_byte_start;

	current_byte_start = 0;
	step = str_asm->start;
	while (step && step->next)
	{
		count_byte(step, num_struct(step));
		str_asm->byte_cnt += step->num_byte;
		step->num_byte_from_start = current_byte_start;
		current_byte_start = str_asm->byte_cnt;
		step = step->next;
	}
}

void		read_file(t_com *commands, t_main *str_asm)
{
	t_com	*step;

	step = commands;
	while (step->next)
	{
		kod_instr(step, str_asm);
		step = step->next;
	}
}

void		assembler(t_com *commands, t_ch player, t_main *str_asm)
{
	ft_initial_asm(str_asm, commands);
	champ_head(str_asm, &player, commands);
	read_file(commands, str_asm);
}
