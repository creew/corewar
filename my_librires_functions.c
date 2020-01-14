/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_librires_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:02:35 by tmelia            #+#    #+#             */
/*   Updated: 2020/01/14 12:02:38 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awm.h"

int		ft_is_strstr(char *src, char *to_find)
{
	int i;
	int j;

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
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
}

static int		new_str(char **str, int fd, char **line)
{
	size_t		len;
	char		*tmp;
	int			flag;

	len = 0;
	while (str[fd][len] != '\0' && str[fd][len] != '\n')
		len++;
	flag = str[fd][len] == '\n' ? 1 : 0;
	*line = ft_strsub(str[fd], 0, len);
	tmp = ft_strdup(str[fd] + len + (str[fd][len] == '\n' ? 1 : 0));
	free(str[fd]);
	if (tmp != '\0')
		str[fd] = tmp;
	return (flag);
}

int				get_row(const int fd, char **line)
{
	static char	*str[1000];
	char		*tmp;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		(str[fd] == NULL) ? str[fd] = ft_strnew(1) : 0;
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (!str[fd] || (str[fd] && str[fd][0] == '\0')))
	{
		free(str[fd]);
		return (0);
	}
	return (new_str(str, fd, line));
}