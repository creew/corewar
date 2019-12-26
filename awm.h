//
// Created by Taren Melia on 26/12/2019.
//

#ifndef COREWAR_AWM_H
#define COREWAR_AWM_H

#include "libft/src/libft.h"
#include "libft/src/get_next_line.h"
#include "op.h"
#include "libft/incl/printf.h"

typedef struct s_champ
{
	char	*name;
	char	*comment;
	int		fd;
}				t_ch;


char			**ft_my_strsplit(char const *s, char c);
#endif //COREWAR_AWM_H
