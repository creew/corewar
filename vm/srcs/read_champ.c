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

static t_result		close_and_ret(int f, t_player **alloc, t_result err)
{
	close(f);
	ft_memdel((void **)alloc);
	return (err);
}

static t_result		create_player(t_header *header, t_player **player, int id)
{
	t_player *pl;

	pl = ft_memalloc(sizeof(t_player) +
		sizeof(char) * swap_uint_be(header->prog_size));
	if (pl == NULL)
		return (ERR_ENOMEM);
	pl->player_id = id;
	pl->prog_size = swap_uint_be(header->prog_size);
	ft_strlcpy(pl->name, header->prog_name, sizeof(pl->name));
	ft_strlcpy(pl->comment, header->comment, sizeof(pl->comment));
	*player = pl;
	return (RET_OK);
}

t_result			read_champ(char *filename, t_player **player, int id)
{
	int			f;
	t_header	header;
	t_uint		player_size;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (ERR_OPEN_CHAMP);
	if (read(f, &header, sizeof(header)) != sizeof(header))
		return (close_and_ret(f, NULL, ERR_READ_CHAMP));
	if (swap_uint_be(header.magic) != COREWAR_EXEC_MAGIC)
		return (close_and_ret(f, NULL, ERR_WRONG_MAGIC));
	player_size = swap_uint_be(header.prog_size);
	if (player_size > CHAMP_MAX_SIZE)
		return (close_and_ret(f, NULL, ERR_CHAMP_TO_BIG));
	if (player_size == 0)
		return (close_and_ret(f, NULL, ERR_CHAMP_ZEROSIZE));
	if (create_player(&header, player, id) != RET_OK)
		return (close_and_ret(f, NULL, ERR_ENOMEM));
	if (read(f, (*player)->prog, player_size) != player_size)
		return (close_and_ret(f, player, ERR_READ_BODY_CHAMP));
	close(f);
	return (RET_OK);
}
