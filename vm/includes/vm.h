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
#include "visu.h"

typedef unsigned int	t_uint;
typedef unsigned short	t_ushort;
typedef unsigned char	t_uchar;

typedef struct		s_carriage {
	t_uint			pc;
	t_uchar			regs[REG_NUMBER][REG_SIZE];
	t_uchar 		carry;
}					t_carriage;

typedef struct		s_color
{
	t_uchar			r;
	t_uchar			g;
	t_uchar			b;
	t_uchar			a;
}					t_color;

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
	int			visualize;
	int			started;
	int			delay;
	t_ushort	field[MEM_SIZE];
	t_vis		vis;
}					t_vm;

int			read_option(int ac, char *av[]);
t_result	read_champ(char *filename, t_player **player);
t_ushort	swap_ushort_be(t_ushort a);
t_uint		swap_uint_be(t_uint a);

void		init_vm(t_vm *vm);

void		start_pause(t_vm *vm);
void 		inc_counter(t_vm *vm);

void 		draw_all(t_vis *vis, t_vm *vm);
int			process_event(t_vis *vis, t_vm *vm);
#endif
