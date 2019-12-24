/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:33:33 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 13:33:33 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
#define VM_H

#include "libft.h"
#include "op.h"
#include "errors.h"

typedef unsigned int	t_uint;
typedef unsigned short	t_ushort;

typedef struct		s_carriage {
	t_uint			pos;
}					t_carriage;

typedef struct		s_player {
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	t_uint 			prog_size;
	t_uint			pl_start;
	t_ftarray		carriages;
	unsigned char	prog[1];
}					t_player;

typedef struct		s_vm {
	t_ftarray	players;
	size_t		cycles;
	int			started;
	int			delay;
	t_uint		field[MEM_SIZE];
}					t_vm;

int			read_option(int ac, char *av[]);
t_result	read_champ(char *filename, t_player **player);
t_ushort	read_ushort_be(t_ushort a);
t_uint		read_uint_be(t_uint a);

void		start_pause(t_vm *vm);
#endif
