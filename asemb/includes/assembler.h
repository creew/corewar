/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <rmarni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:11:57 by rmarni            #+#    #+#             */
/*   Updated: 2019/12/26 16:43:23 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_ASSEMBLER_H
# define ASSEMBLER_ASSEMBLER_H

# include "op.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdlib.h>
# include <fcntl.h>
# include "awm.h"

# define BLACK(string)			"\x1b[30m" string "\x1b[0m"
# define RED(string)			"\x1b[31m" string "\x1b[0m"
# define GREEN(string)			"\x1b[32m" string "\x1b[0m"
# define YELLOW(string)			"\x1b[33m" string "\x1b[0m"
# define BLUE(string)			"\x1b[34m" string "\x1b[0m"
# define MAGENTA(string)		"\x1b[35m" string "\x1b[0m"
# define CYAN(string)			"\x1b[36m" string "\x1b[0m"
# define GREY(string)			"\x1b[37m" string "\x1b[0m"
# define RESET(string)			"\x1b[0m" string "\x1b[0m"

extern t_op		g_op_tab[17];

typedef struct	s_main
{
	char	*name;
	int		fd;
	int		byte_cnt;
	t_com	*start;
	int		neg_num_zero;
	char	*tmp;
}				t_main;

void			ft_exit(int num);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_write_hex(char c, t_main *st_asm);
void			hex_convert(char *str, t_main *st_asm, int num_byte);
void			champ_head(t_main *str_asm, t_ch *player);
int				code_convert(char *str);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcpy(char *dest, const char *src);
void			kod_instr(t_com *commands, t_main *str_asm);
char			**ft_my_strsplit(char const *s, char c);
int				ft_is_strstr(char *src, char *to_find);
char			*ft_strdup(const char *src);
void			clear_commands(t_com **coms);
void			clear_player(t_ch *player);
void			count_byte(t_com *commands, int i);
void			put_num_byte(t_main *str_asm);
void			ft_initial_asm(t_main *str_asm, t_com *commands);
void			write_to_file(t_main *str_asm, int num, int int_c);
void			arg_code(t_com *i_ams);
void			write_arg_to_file(t_main *str_asm, t_com *i_ams, int i);
void			errors_code(int num);
int				is_num(char sym);
int				num_struct(t_com *commands);
void			ft_check_extention(char *str, t_main *str_asm);
void			assembler(t_com *commands, t_ch player, char *av,
					t_main *str_asm);
#endif
