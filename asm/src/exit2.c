/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:37:10 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/15 13:37:11 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void		errors_code3(int num)
{
	char	*tmp;

	tmp = NULL;
	if (num == 16)
		tmp = "not valid command\n";
	else if (num == 17)
		tmp = "invalid end of line\n";
	else if (num == 18)
		tmp = "args is not valid\n";
	else if (num == 19)
		tmp = "invalid syntax\n";
	else if (num == 20)
		tmp = "expected line break\n";
	else if (num == 21)
		tmp = "the camp has not commands\n";
	else if (num == 22)
		tmp = "label does not exist\n";
	else if (num == 23)
		tmp = "expected end of line after \"\n";
	ft_printf("%s", tmp);
}

void		errors_code2(int num)
{
	char *tmp;

	if (num == 8)
		tmp = "expected end of line after name\n";
	else if (num == 9)
		tmp = "comment already exists\n";
	else if (num == 10)
		tmp = "expected champion comment in characters \" \"\n";
	else if (num == 11)
		tmp = "cooment is too long\n";
	else if (num == 12)
		tmp = "expected end of line after name\n";
	else if (num == 13)
		tmp = "invalid characters, "
"must be the name or comment of the champion\n";
	else if (num == 14)
		tmp = "Chimpion name or comment does not exist\n";
	else if (num == 15)
		tmp = "not valid label\n";
	else
	{
		errors_code3(num);
		return ;
	}
	ft_printf("%s", tmp);
}

void		ft_exit2(int num, int row)
{
	int		i;

	i = row;
	ft_printf(RED("ERROR: "));
	errors_code(num);
	ft_printf("ROW - %d\n", row);
	exit(0);
}
