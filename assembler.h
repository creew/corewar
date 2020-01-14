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
# include "ft_printf/includes/ft_printf.h"
# include "libft/src/libft.h"
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


extern t_op    op_tab[17];


//typedef struct s_commands
//{
//	char	*name;
//	char	*arg1;
//	char	*arg2;
//	char	*arg3;
//	char	*label;
//	int		count_args;
//	int 	num_byte;				//q byte;
//	int 	num_byte_from_start;
//	unsigned char 	kod_arg;		//коды элементов в байте;
//	struct s_commands *next;
//}			t_com;

typedef struct	s_main
{
	char	*name;
	int 	fd;
	int 	byte_cnt;
	t_com	*start;
	int 	neg_num_zero;
	char 	*tmp;
}				t_main;
/*
typedef struct 	s_instr
{
	char			*metka;					//метка операции;
	char			kod;					//код операции;
	char			*name;					//имя операции;
	char			*arg1;
	char			*arg2;
	char			*arg3;
	int				size_t_dir;				//размер T_DIR;
	int				is_kod;					//atribute code;
	unsigned char 	kod_arg;			//коды элементов в байте;

}				t_instr;
*/
//typedef struct s_champ
//{
//	char	*name;
//	char	*comment;
//	int		fd;
//}				t_ch;
//
//typedef	struct	s_valid
//{
//	int		(*valid_com[16])(t_com *commands);
//}				t_valid;

int				get_next_line(const int fd, char **line);
void			ft_exit(int num);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_write_hex(char c, t_main *st_asm);
void			hex_convert(char *str, t_main *st_asm, int num_byte);
void			champ_head(t_main *str_asm, t_ch *player, t_com *commands);
int				code_convert(char *str);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcpy(char *dest, const char *src);
void			kod_instr(t_com *commands, t_main *str_asm);
static char		can_use_command[16][8];
static	char	 can_use_args[3][5];
char			**ft_my_strsplit(char const *s, char c);
int				ft_is_strstr(char *src, char *to_find);
char   			 *ft_strdup(const char *src);
void			clear_commands(t_com **coms);
void			clear_player(t_ch *player);
int				 gleb (char *str, t_ch *player, t_com **commands);
char   			*gleb_strtrim(char const *s);
char   			*gleb_strsub(char const *s, unsigned int start, size_t len);
void			count_byte(t_com *commands, int i);
void			put_num_byte(t_main *str_asm);

#endif
