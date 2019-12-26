/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 16:35:21 by rmarni            #+#    #+#             */
/*   Updated: 2019/11/30 19:30:40 by rmarni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_where_n(char *s)
{
	int			i;

	i = 0;
	if (s[0] == '\n')
		return (0);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int				ft_give_line(char **str, char **line, int fd)
{
	char		*tmp;
	int			num_n;

	num_n = ft_where_n(str[fd]);
	if (str[fd][num_n] == '\0' || str[fd][num_n + 1] == '\0')
	{
		if (str[fd][num_n] == '\n')
			*line = ft_strcpy(*line, "\n");
		else
			*line = ft_strsub(str[fd], 0, num_n);
		free(str[fd]);
		str[fd] = NULL;
		return (1);
	}
	*line = ft_strsub(str[fd], 0, num_n);
	*line = ft_strcpy(*line, "\n");
	tmp = ft_strdup(str[fd] + (num_n + 1));
	ft_strdel(&str[fd]);
	str[fd] = tmp;
	return (1);
}

int				get_next_line(const int fd, char **line)
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
	return (ft_give_line(s, line, fd));
}
