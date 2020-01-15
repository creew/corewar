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
# define VM_H

# include "libft.h"
# include "op.h"
# include "errors.h"
# include "visu.h"

typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;
typedef unsigned short	t_ushort;
typedef unsigned char	t_uchar;

extern	t_op		g_op_tab[17];

typedef enum {
	NOT_INITED,
	WAITING
}	t_pstates;

typedef enum {
	VALID = 0,
	INVALID = 1
}	t_valids;

typedef enum {
	PAUSED,
	RUNNING,
	FINISHED
}	t_gstate;

# define VERB_SHOW_LIVES         (1u << 0u)
# define VERB_SHOW_CYCLES        (1u << 1u)
# define VERB_SHOW_OPERATIONS    (1u << 2u)
# define VERB_SHOW_DEATHS        (1u << 3u)
# define VERB_SHOW_MOVES         (1u << 4u)

# define SIGNED		(1)
# define UNSIGNED	(0)

# define A1 (0)
# define A2 (1)
# define A3 (2)

typedef struct	s_fieldelem
{
	t_uchar				id;
	t_uchar				live;
	t_uchar				fresh;
	t_uchar				cmd;
}				t_fieldelem;

typedef struct	s_process
{
	struct s_process	*prev;
	struct s_process	*next;
	size_t				id;
	t_uchar				player_id;
	t_uchar				carry;
	t_uchar				opcode;
	t_uchar				state;
	int					pc;
	t_uchar				regs[REG_NUMBER][REG_SIZE];
	t_uint				wait;
	int					cycle_live;
}				t_process;

typedef struct	s_player {
	int					player_id;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	t_uint				prog_size;
	size_t				last_live;
	size_t				live_in_session;
	unsigned char		prog[1];
}				t_player;

typedef struct	s_vm {
	t_player			*players[MAX_PLAYERS];
	t_player			*pl_tmp[MAX_PLAYERS];
	size_t				count_players;
	size_t				count_pl_tmp;
	t_player			*last_player;
	t_process			*processes_root;
	size_t				process_count;
	int					cycles;
	int					cycle_to_die;
	size_t				cycles_check;
	size_t				live;
	size_t				checks;
	t_gstate			state;
	t_fieldelem			field[MEM_SIZE];
	t_vis				vis;
	size_t				do_steps;
	int					do_dump;
	int					dump_n;
	int					do_debug;
	t_uint				debug_args;
	int					visualize;
	int					print_aff;
}				t_vm;

typedef struct	s_runner
{
	t_fieldelem			*field;
	t_uint				arg;
	long				args[3];
	char				types[3];
	int					skip;
}				t_runner;

t_result		read_option(t_vm *vm, int ac, char *av[]);
t_result		read_champ(char *filename, t_player **player, int id);

void			init_vm(t_vm *vm);

void			start_pause(t_vm *vm);
void			inc_counter(t_vm *vm);

void			draw_all(t_vis *vis, t_vm *vm);
int				process_event(t_vis *vis, t_vm *vm);

t_process		*add_process(t_process **root, t_uint id, long pc,
					size_t *count);
void			remove_process(t_process **root, t_process *pr, size_t *count);
t_process		*copy_process(t_process **root, t_process *copy, long pc,
					size_t *count);

t_uint			swap_uint_be(t_uint a);
void			write_varlen_be(t_uchar *data, t_ulong val, t_uint size);
long			read_varlen_be(const t_uchar *data, t_uint size, int is_signed);
long			read_be_map(const t_fieldelem *data, long offset,
					t_uint size, int boolean);
void			set_field_vals(t_fieldelem *field, long pos, t_process *pr,
					long reg);

int				check_arguments(t_process *pr, t_runner *run, int index);
void			process_cycle(t_vm *vm);

void			process_live_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_ld_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_st_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_add_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_sub_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_and_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_or_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_xor_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_zjmp_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_ldi_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_sti_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_fork_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_lld_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_lldi_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_lfork_run(t_vm *vm, t_process *pr, t_runner *run);
void			process_aff_run(t_vm *vm, t_process *pr, t_runner *run);

void			draw_info(t_vis *vis, t_vm *vm);
void			draw_carriages(t_vis *vis, t_vm *vm);
void			draw_carriage(t_vis *vis, int col, int row, int pid);

void			create_dump(t_vm *vm, int chars_in_line);

t_result		get_next_free_index(t_player **arr, int *player_id,
					size_t size);
int				is_player_index_free(t_player **arr, int player_id,
					size_t size);

t_result		parse_arg(t_vm *vm, int *index, int ac, char *av[]);

t_ulong			get_reg_dir_ind_arg(t_process *pr, t_runner *run, t_uint arg);
t_ulong			get_reg_dir_arg(t_process *pr, t_runner *run, t_uint arg);
t_ulong			get_dir_ind_arg(t_process *pr, t_runner *run, t_uint arg);
void			exec_process(t_vm *vm, t_process *pr);

int				check_reg(t_op *op, t_uint id, t_process *pr, t_runner *runner);
int				check_dir(t_op *op, t_uint id, t_process *pr, t_runner *runner);
int				check_ind(t_op *op, t_uint id, t_process *pr, t_runner *runner);
void			print_usage();
#endif
