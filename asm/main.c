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
//	 	printf("\nname ----        %s\ncomment  ------     %s\n", player.name, player.comment);
//	 while (commands)
//	 {
//	 	printf("label - %s\n", commands->label);
//	 	printf("name - %s\n", commands->name);
//	 	printf("arg1 - %s\n", commands->arg1);
//	 	printf("arg2 - %s\n", commands->arg2);
//	 	printf("arg3 - %s\n", commands->arg3);
//	 	printf("--------------------------\n");
//	 	commands = commands->next;
//	 }
	assembler(commands, player, argv[1]);
	clear_commands(&commands);
	clear_player(&player);
	return (1);
}
