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

	ft_check_extention(argv[1], &str_asm);
	init(argv[1], &commands, &player);
	close(player.fd);
	assembler(commands, player, &str_asm);
	clear_commands(&commands);
	clear_player(&player);
	return (1);
}
