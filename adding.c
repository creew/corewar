#include "awm.h"

void	add_comment(char *str, t_ch *player)
{
    int i;

    i = 1;
    if (player->comment != NULL)
        ft_exit();
    while (*str != '"' && *str != '\0')
        str++;
    if (*str == '\0')
        ft_exit();
    while (str[i] != '"' && str[i] != '\0')
        i++;
    if (str[i] == '\0')
    {
        add_with_n_comment(player, ft_strdup(1 + str));
        if (ft_strlen(player->comment) >= COMMENT_LENGTH)
            ft_exit();
        return;
    }
    if (str[i + 1] && str[i + 1] != '\0')
        ft_exit();
    player->comment = ft_strsub(str, 1, i - 1);
    if (ft_strlen(player->comment) >= COMMENT_LENGTH)
        ft_exit();
}

void	add_with_n_comment(t_ch *player, char *str)
{
    int i;
    char *line;
    char *s;

    line = NULL;
    if (!player->comment && *str != '"')
        player->comment = ft_strdup(str);
    else if (*str != '"')
    {
        line = ft_strjoin(str, "\n");
        s = ft_strdup(player->comment);
        free(player->comment);
        player->comment = ft_strjoin(s, line);
        free(s);
        free(line);
    }
    i = 0;
    while (str[i] != '\0' && str[i] != '"')
        i++;
    free(str);
    if (str[i] == '\0')
    {
        get_next_line(player->fd, &line);
        add_with_n_comment(player, line);
    }
    if (str[i] == '"')
    {
        i++;
        while (str[i] != '\0')
        {
            if (str[i] != ' ' && str[i] != '\t')
                ft_exit();
            i++;
        }
    }
}

void	add_name(char *str, t_ch *player)
{
    int i;

    i = 1;
    if (player->name != NULL)
        ft_exit();
    while (*str != '"' && *str != '\0')
        str++;
    if (*str == '\0')
        ft_exit();
    while (str[i] != '"' && str[i] != '\0')
        i++;
    if (str[i] == '\0')
    {
        add_with_n_name(player, ft_strdup(1 + str));
        if (ft_strlen(player->name) > PROG_NAME_LENGTH)
            ft_exit();
        return;
    }
    if (str[i] == '\0')
        ft_exit();
    if (str[i + 1] && str[i + 1] != '\0')
        ft_exit();
    player->name = ft_strsub(str, 1, i - 1);
    if (ft_strlen(player->name) > PROG_NAME_LENGTH)
        ft_exit();
}


void	add_with_n_name(t_ch *player, char *str)
{
    int i;
    char *line;
    char *s;

    line = NULL;
    if (!player->name && *str != '"')
        player->name = ft_strdup(str);
    else if (*str != '"')
    {
        line = ft_strjoin(str, "\n");
        s = ft_strdup(player->name);
        free(player->name);
        player->name = ft_strjoin(s, line);
        free(s);
        free(line);
    }
    i = 0;
    while (str[i] != '\0' && str[i] != '"')
        i++;
    free(str);
    if (str[i] == '\0')
    {
        get_next_line(player->fd, &line);
        add_with_n_name(player, line);
    }
    if (str[i] == '"')
    {
        i++;
        while (str[i] != '\0')
        {
            if (str[i] != ' ' && str[i] != '\t')
                ft_exit();
            i++;
        }
    }
}

void		add_args(char **line, t_com *commands)
{
    char **args;
    int		i;
    char *s;
    char *q;

    s = ft_strtrim(*line);
    q = s;
    i = 0;
    while (*s != ' ' && *s != DIRECT_CHAR && *s != '-')
        s++;
    while (s[i] != '\0')
        i++;
    if (s[i - 1] == SEPARATOR_CHAR)
        ft_exit();
    args = ft_my_strsplit(s, SEPARATOR_CHAR);
    if (args[0])
    {
        commands->arg1 = ft_strtrim(args[0]);
        commands->count_args++;
        free(args[0]);
    }
    if (args[1])
    {
        commands->arg2 = ft_strtrim(args[1]);
        commands->count_args++;
        free(args[1]);
    }
    if (args[2])
    {
        commands->arg3 = ft_strtrim(args[2]);
        commands->count_args++;
        free(args[2]);
    }
    free(args);
    free(q);
}