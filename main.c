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

#include "awm.h"

int	main(int argc, char **argv)
{
	t_com	*commands;
	t_ch	player;

	init(argv[1], &commands, &player);
	assembler(commands, player, argv[1]);
	clear_commands(&commands);
	clear_player(&player);
	return (1);
}
