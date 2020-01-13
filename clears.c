#include "awm.h"

void	clear_commands(t_com **coms)
{
    t_com *q;

    while (*coms && (*coms)->next)
    {
        q = *coms;
        (*coms) = (*coms)->next;
        free(q->name);
        free(q->arg2);
        free(q->arg1);
        free(q->arg3);
        free(q->label);
        free(q);
    }
    free((*coms)->name);
    free((*coms)->arg2);
    free((*coms)->label);
    free((*coms)->arg1);
    free((*coms)->arg3);
    free(*coms);
}

void	clear_line(char **str)
{
    if (str && *str != NULL)
    {
        free(*str);
        *str = NULL;
    }
}

void	clear_player(t_ch *player)
{
    free(player->name);
    free(player->comment);
}

void	ft_exit(void)
{
    ft_printf(RED("Error\n"));
    exit(0);
}

void	ft_exit2(char *str, int row)
{
	ft_printf(RED("ERROR"));
	ft_printf(": %s\n ", str);
	if (row > 0)
		ft_printf("СТРОКА %d\n", row);
	exit(0);
}