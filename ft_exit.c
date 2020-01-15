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

void		errors_code(int num)
{
	char	*tmp;

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
	else if (num == 5)
		tmp = "name already exists\n";
	else if (num == 6)
		tmp = "expected champion name in characters \" \"\n";
	else if (num == 7)
		tmp = "name is too long\n";
	printf("%s", tmp);
}

void		ft_exit(int num)
{
	ft_printf(RED("ERROR: "));
	errors_code(num);
	exit(0);
}

void		ft_exit2(int num, int row)
{
	ft_printf(RED("ERROR: "));
	errors_code(num);
	ft_printf("ROW - %d\n", row);
}
