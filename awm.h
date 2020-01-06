#ifndef COREWAR_AWM_H
#define COREWAR_AWM_H

#include "libft/src/libft.h"
#include "libft/src/get_next_line.h"
#include "op.h"
#include "libft/incl/printf.h"

typedef struct s_commands
{
	char	*name;
	char	*arg1;
	char	*arg2;
	char	*arg3;
	char	*label;
	int		count_args;
	struct s_commands *next;
}			t_com;

typedef struct s_champ
{
	char	*name;
	char	*comment;
	int		fd;
}				t_ch;

typedef	struct	s_valid
{
	int		(*valid_com[16])(t_com *commands);
	int		(*valid_args[3])(t_com *commands);
	char	can_use_command[16][8];
}				t_valid;

char			**ft_my_strsplit(char const *s, char c);
int				ft_is_strstr(char *src, char *to_find);
int     		valid_fork(t_com *commands);
int     		valid_lfork(t_com *commands);
int		        valid_lld(t_com *commands);
int		        valid_aff(t_com *commands);
int		        valid_args(t_com *commands, t_valid validator);
int		        valid_lld_arg(t_com *commands);
int     		valid_arg_dir(char	*str, t_com *commands);
int		        valid_arg_reg(char *str);
int		        valid_sti(t_com *commands);
int		        valid_sti_arg(t_com *commands);
int     		valid_or(t_com *commands);
int		        valid_xor(t_com *commands);
int		        valid_zjmp(t_com *commands);
int		        valid_ldi(t_com *commands);
int		        valid_lldi(t_com *commands);
int		        valid_xor_arg(t_com *commands);
int     		valid_ldi_arg(t_com *commands);
int     		valid_lldi_arg(t_com *commands);
int		        valid_or_arg(t_com *commands);
int     		valid_ld_arg(t_com *commands);
int     		valid_st_arg(t_com *commands);
int		        valid_add_arg(t_com *commands);
int     		valid_sub_arg(t_com *commands);
int     		valid_and_arg(t_com *commands);
int		        valid_ld(t_com *commands);
int     		valid_st(t_com *commands);
int     		valid_add(t_com *commands);
int     		valid_sub(t_com *commands);
int     		valid_and(t_com *commands);
int     		valid_live(t_com *commands);
int		        valid_arg_int(char *str);
int     		is_command(char *line, t_valid validator);
int     		it_s_label(char *line);
int     		command_is_valid(char *command, t_valid validator);
int     		label_is(char *str, t_com *commands);
int             it_s_comment(char *line);
void        	add_comment(char *str, t_ch *player);
void	        ft_exit(void);
void        	add_with_n_comment(t_ch *player, char *str);
int             it_s_name(char *line);
void        	add_name(char *str, t_ch *player);
void        	add_with_n_name(t_ch *player, char *str);
void    		add_args(char **line, t_com *commands);
void	        add_command_with_label(char **line, t_com *command);
void        	add_command(char *line, t_com *command);
void        	add_label(char *line, t_com *commands);
void        	init_args(void);
void	        init_command(t_valid *validator);
void        	init_validator(t_valid *validator);
t_com       	*lst_create_commands(void);
int     		valid_label(char *label);
int     		ft_word_length(char const *s, char c);
int	        	count_words(char const *s, char c);
void        	ft_delete_tabs(char *str);
void        	clear_commands(t_com **coms);
void        	clear_line(char **str);
void	        clear_player(t_ch *player);
int     		valid_labeles(t_com *head);
int     		l_and_c_one_rows(char *line);
void        	delete_comment(char *str);
void			set_player(t_ch *player, char *str);
void			set_commands(t_ch player, t_com *commands);
void			work_with_command(char *q, t_com **commands, t_valid validator);
void			wokr_with_label(char *q, t_com **commands, t_valid validator);
void			set_player(t_ch *player, char *str);
void			init_line(char **line, char **q);
int				ft_strsubpos(char *str, char c);
#endif //COREWAR_AWM_H
