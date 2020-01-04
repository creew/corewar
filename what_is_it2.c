#include "awm.h"

int		command_is_valid(char *command)
{
    int i;

    i = 0;
    while (i < 16 && command)
    {
        if (ft_strcmp(command, can_use_command[i]) == 0)
            return (1);
        i++;
    }
    ft_exit();
    return (0);
}

int		l_and_c_one_rows(char *line)
{
    int i;

    i = 0;
    while (line[i] != LABEL_CHAR)
        i++;
    if (line[i + 1] && line[i + 1] != '\0')
        return (1);
    return (0);
}