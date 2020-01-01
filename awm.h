//
// Created by Taren Melia on 26/12/2019.
//

#ifndef COREWAR_AWM_H
#define COREWAR_AWM_H

#include "libft/src/libft.h"
#include "libft/src/get_next_line.h"
#include "op.h"
#include "libft/incl/printf.h"

static char	can_use_command[16][8];
static	char can_use_args[3][5];

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
}				t_valid;

char			**ft_my_strsplit(char const *s, char c);
int				ft_is_strstr(char *src, char *to_find);
#endif //COREWAR_AWM_H
