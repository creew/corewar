#include "awm.h"

void	add_comment(char *str, t_ch *player)
{
    int i;

    i = 1;
    if (player->comment != NULL)
        ft_exit2("коммент уже существует", player->row);
    while (*str != '"' && *str != '\0')
        str++;
	if (*str == '\0')
		ft_exit2("ожидалось имя чемпиона в символах \" \"",  player->row);
    while (str[i] != '"' && str[i] != '\0')
        i++;
    if (str[i] == '\0')
    {
        add_with_n_comment(player, ft_strdup(1 + str));
        if (ft_strlen(player->comment) > COMMENT_LENGTH)
            ft_exit2("длина комментария слишком большая", player->row);
        return;
    }
    if (str[i + 1] && str[i + 1] != '\0')
        ft_exit2("ожидлася конец строки после комментария", player->row);
    player->comment = ft_strsub(str, 1, i - 1);
    if (ft_strlen(player->comment) > COMMENT_LENGTH)
		ft_exit2("длина комментария слишком большая", player->row);
}

void	add_with_n_comment(t_ch *player, char *str)
{
    int i;
    char *line;
    char *s;

    line = NULL;
    if (*str != '"')
    {
		i = 0;
		while (str[i] != '\0' && str[i] != '"')
			i++;
		line = (str[i] == '\0') ?
			ft_strjoin(str, "\n") :
				ft_strsub(str, 0, i);
        s = ft_strdup(player->comment);
        free(player->comment);
        player->comment = s ? ft_strjoin(s, line) : ft_strdup(line);
        free(s);
        free(line);
    }
	end_name_or_comment(&str, i, &line, player);
}

void	add_name(char *str, t_ch *player)
{
    int i;

    i = 1;
    if (player->name != NULL)
        ft_exit2("имя уже существует", player->row);
    while (*str != '"' && *str != '\0')
        str++;
    if (*str == '\0')
        ft_exit2("ожидалось имя чемпиона в символах \" \"",  player->row);
    while (str[i] != '"' && str[i] != '\0')
        i++;
    if (str[i] == '\0')
    {
        add_with_n_name(player, ft_strdup(1 + str));
		if (ft_strlen(player->name) > PROG_NAME_LENGTH)
			ft_exit2("длина имени слишком большая", player->row);
        return;
    }
    (str[i + 1] && str[i + 1] != '\0') ? ft_exit2("ожидался конец строки после имени", player->row) : 0;
    player->name = ft_strsub(str, 1, i - 1);
	if (ft_strlen(player->name) > PROG_NAME_LENGTH)
		ft_exit2("длина имени слишком большая", player->row);
}

void	add_with_n_name(t_ch *player, char *str)
{
    int i;
    char *line;
    char *s;

    line = NULL;
    if (*str != '"')
    {
		i = 0;
		while (str[i] != '\0' && str[i] != '"')
			i++;
		line = (str[i] == '\0') ?
				ft_strjoin(str, "\n") :
					ft_strsub(str, 0, i);
        s = ft_strdup(player->name);
        free(player->name);
        player->name = s ? ft_strjoin(s, line) : ft_strdup(line);
        free(s);
        free(line);
    }
    end_name_or_comment(&str, i, &line, player);
}

void		add_args(char **line, t_com *commands, t_ch player)
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
        ft_exit2("не валидное окончание строки", player.row);
    args = ft_my_strsplit(s, SEPARATOR_CHAR);
    adding_args(args, commands);
    free(q);
}