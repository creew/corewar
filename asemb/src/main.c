/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:17:51 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 15:17:53 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int	main(int argc, char **argv)
{
	t_com	*commands;
	t_ch	player;
	t_main	str_asm;

	if (argc > 1)
	{
		ft_check_extention(argv[argc - 1], &str_asm);
		init(argv[argc - 1], &commands, &player);
		assembler(commands, player, argv[argc - 1], &str_asm);
		ft_printf("Writing output program to %s\n", str_asm.name);
		ft_strdel(&str_asm.name);
		clear_commands(&commands);
		clear_player(&player);
	}
	else
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
