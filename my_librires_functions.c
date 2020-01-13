#include "awm.h"

char			**ft_my_strsplit(char const *s, char c)
{
    char		**my_tab;
    int			i;
    int			nb_words;

    i = 0;
    if (!s)
        return (NULL);
    nb_words = count_words(s, c);
    my_tab = (char **)malloc(sizeof(char *) * (nb_words + 2));
    if (my_tab == NULL)
        return (NULL);
    while (nb_words--)
    {
        while (*s == c && *s != '\0')
            s++;
        if (*s == '"')
        {
            s++;
            (my_tab[i++] = ft_strsub(s, 0, ft_word_length(s, '"')));
            while (*s != '"' && *s != '\0')
                s++;
            if (*s != '\0')
                s++;
            continue;
        }
        if ((my_tab[i++] = ft_strsub(s, 0, ft_word_length(s, c))) == NULL)
        {
            free(my_tab);
            return (NULL);
        }
        s += ft_word_length(s, c);
    }
    my_tab[i] = NULL;
    my_tab[i + 1] = NULL;
    return (my_tab);
}

int		ft_is_strstr(char *src, char *to_find)
{
    int i;
    int j;

    j = 0;
    i = 0;
    if (to_find[i] == '\0')
        return (0);
    while (src[i] != '\0')
    {
        j = 0;
        while (src[i + j] == to_find[j])
        {
            if (to_find[j + 1] == '\0')
            {
                if (src[i + j + 1] == '\0' || src[i + j + 1] == ' ')
                    return (1);
                return (0);
            }
            j++;
        }
        i++;
    }
    return (0);
}

void	ft_delete_tabs(char *str)
{
    int i;

    i = 0;
    if (!str)
		return;
    while (str[i] != '\0')
    {
        if (str[i] == '\t')
            str[i] = ' ';
        i++;
    }
}

int		ft_strsubpos(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int				ft_where_is_n(char *s)
{
	int			i;

	i = 0;
	if (s[0] == '\n')
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int				ft_give_row(char **str, char **line, int fd)
{
	char		*tmp;
	int			num_n;

	num_n = ft_where_is_n(str[fd]);
	if (str[fd][num_n] == '\0')
	{
		*line = ft_strsub(str[fd], 0, num_n);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	*line = ft_strsub(str[fd], 0, num_n);
	tmp = ft_strdup(str[fd] + num_n + 1);
	ft_strdel(&str[fd]);
	str[fd] = tmp;
	return (1);
}

int				get_row(const int fd, char **line)
{
	size_t		ret;
	static char	*s[4864];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE) > 0))
	{
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (ret == 0 && s[fd] == NULL)
		return (0);
	return (ft_give_row(s, line, fd));
}