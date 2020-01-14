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
//#include "libft/incl/libft.h"

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

void			champ_head(t_main *str_asm, t_ch *player, t_com *commands)
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
