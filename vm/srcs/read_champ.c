/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:35:40 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 13:35:41 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>
#include <fcntl.h>

t_result	close_and_ret(int f, void *alloc, t_result err)
{
	close(f);
	ft_memdel(&alloc);
	return (err);
}

t_result	read_champ(char *filename, t_player **player)
{
	int			f;
	t_header	header;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (ERR_OPEN_CHAMP);
	if (read(f, &header, sizeof(header)) != sizeof(header))
		return (close_and_ret(f, NULL, ERR_READ_CHAMP));
	if (read_uint_be(header.magic) != COREWAR_EXEC_MAGIC)
		return (close_and_ret(f, NULL, ERR_WRONG_MAGIC));
	t_uint player_size = read_uint_be(header.prog_size);
	if (player_size > CHAMP_MAX_SIZE)
		return (close_and_ret(f, NULL, ERR_CHAMP_TO_BIG));
	t_player *pl = ft_memalloc(sizeof(t_player) + sizeof(char) * player_size);
	if (pl == NULL)
		return (close_and_ret(f, NULL, ERR_ENOMEM));
	if (read(f, pl->prog, player_size) != player_size)
		return (close_and_ret(f, pl, ERR_READ_BODY_CHAMP));
	ft_strlcpy(pl->name, header.prog_name, sizeof(pl->name));
	ft_strlcpy(pl->comment, header.comment, sizeof(pl->comment));
	*player = pl;
	return (RET_OK);
}
