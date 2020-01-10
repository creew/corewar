#include "awm.h"

int		command_is_valid(char *command, t_valid validator, int row)
{
    int i;

    i = 0;
    while (i < 16 && command)
    {
        if (ft_strcmp(command, validator.can_use_command[i]) == 0)
            return (1);
        i++;
    }
    ft_exit2("не валидная команда", row);
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

int	if_the_end_file_with_out_n(char *line)
{
	if (line && ft_strcmp(ft_strtrim(line), "\0") == 0)
		return (0);
	else
		return (1);

}