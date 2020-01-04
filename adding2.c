#include "awm.h"

void	add_command(char *line, t_com *command)
{
    int i;

    i = 0;
    while (line[i] != ' ' && line[i] != '\0' && line[i] != DIRECT_CHAR && line[i] != '-')
        i++;
    command->name = ft_strsub(line, 0, i);
}

void	add_command_with_label(char **line, t_com *command)
{
    int n;
    char *q;

    n = 0;
    while (**line != LABEL_CHAR)
        (*line)++;
    (*line)++;
    q = ft_strtrim(*line);
    while (q[n] != ' ' && q[n] != '\0' && q[n] != DIRECT_CHAR && q[n] != '-')
        n++;
    if (n >= 0)
        command->name = ft_strsub(q, 0, n);
    free(q);
}

void	add_label(char *line, t_com *commands)
{
    char **str;
    char *q;

    str = ft_my_strsplit(line, LABEL_CHAR);
    if (commands->label)
    {
        q = ft_strdup(commands->label);
        free(commands->label);
        commands->label = ft_strjoin(q, " ");
        free(q);
        q = ft_strdup(commands->label);
        free(commands->label);
        commands->label = ft_strjoin(q, str[0]);
        free(q);
    }
    else
        commands->label = ft_strdup(str[0]);
    str[0] ? free(str[0]) : 0;
    str[1] ? free(str[1]) : 0;
    (str[2] && str[1]) ? free(str[2]) : 0;
    free(str);
}