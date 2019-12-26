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
typedef unsigned long	t_ulong;
typedef unsigned short	t_ushort;
typedef unsigned char	t_uchar;
typedef t_ushort		t_fieldelem;


typedef	t_ftarray		t_arrplayers;

typedef enum {
	NOT_INITED,
	WAITING
} t_pstates;

typedef struct		s_process
{
	struct s_process	*prev;
	struct s_process	*next;
	size_t 				id;
	t_uint				player_id;
	t_uint				pc;
	t_uchar				regs[REG_NUMBER][REG_SIZE];
	t_uchar 			carry;
	t_pstates			state;
	t_uint				wait;
	t_uchar 			opcode;
	t_uint 				nbr_live;
}					t_process;

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
	unsigned char	prog[1];
}					t_player;

typedef struct		s_vm {
	t_arrplayers	players;
	t_process		*processes_root;
	size_t			process_max;
	size_t			cycles;
	size_t			cycle_decrease;
	size_t 			live;
	int				visualize;
	int				started;
	t_fieldelem		field[MEM_SIZE];
	t_vis			vis;
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

t_process	*add_process(t_process **root, t_uint id, t_uint pc, size_t *pr_max);
void 		remove_process(t_process **root, t_process *pr);
t_process	*copy_process(t_process **root, t_process *copy,
							   size_t *pr_max, t_uint pc);

void		write_varlen_be(t_uchar *data, t_ulong val, t_uint size);
t_ulong		read_varlen_be(const t_uchar *data, t_uint size);

long		read_be_map(const t_fieldelem *data, int offset,
						t_uint size, int boolean);
void		write_be_map(t_fieldelem *data, t_uint val, t_uint offset, t_uint size);

void		process_processes(t_vm *vm);
#endif
