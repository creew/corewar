/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:51:43 by eklompus          #+#    #+#             */
/*   Updated: 2019/10/04 17:17:06 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static int		find_in_list(t_list *data, void *cmp)
{
	t_fddata	*fd_list;

	fd_list = (t_fddata *)(data->content);
	if (fd_list->fd == *((int *)cmp))
		return (1);
	return (0);
}

static int		parse_read(ssize_t readed, t_fddata *fdlist, char **line)
{
	if (readed < 0)
		return (-1);
	if (readed == 0)
	{
		fdlist->eof = 1;
		if (fdlist->str_len)
		{
			*line = fdlist->str;
			fdlist->str = NULL;
			fdlist->str_len = 0;
			return (1);
		}
		return (0);
	}
	if ((readed + fdlist->str_len + 1) > fdlist->str_size)
	{
		if ((fdlist->str = ft_memrealloc(fdlist->str, fdlist->str_len + 1,
										readed + fdlist->str_len + 1)) == NULL)
			return (-1);
		fdlist->str_size = readed + fdlist->str_len + 1;
	}
	ft_memcpy(fdlist->str + fdlist->str_len, fdlist->buf, readed);
	fdlist->str_len += readed;
	fdlist->str[fdlist->str_len] = '\0';
	return (0);
}

static int		remove_data(t_list **root, int fd, int ret)
{
	t_list		*list;
	t_list		**prev;
	t_fddata	*fddata;

	list = *root;
	prev = root;
	while (list)
	{
		fddata = (t_fddata *)(list->content);
		if (fddata->fd == fd)
		{
			*prev = list->next;
			ft_memdel((void **)&(fddata->str));
			ft_memdel((void **)&(fddata->buf));
			ft_memdel((void **)&(list->content));
			ft_memdel((void **)&(list));
			break ;
		}
		prev = &(list->next);
		list = list->next;
	}
	return (ret);
}

static int		alloc_and_move(t_fddata *data, char **line)
{
	char	*strbuf;
	char	*s;
	size_t	len;

	if (data->str && data->str_len &&
		(s = (char *)ft_memchr(data->str, '\n', data->str_len)))
	{
		len = s - data->str;
		strbuf = ft_memndup(data->str, len + 1);
		if (strbuf == NULL)
			return (-1);
		strbuf[len] = '\0';
		ft_memmove(data->str, s + 1, data->str_len - len);
		data->str_len -= (len + 1);
		*line = strbuf;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*root = NULL;
	t_list			*data;
	int				r;
	t_fddata		*fdl;

	r = 0;
	data = ft_lstfind(root, (void *)&fd, find_in_list);
	if (!data)
	{
		if (!(data = ft_lstaddblank(&root, sizeof(t_fddata))))
			return (-1);
		((t_fddata *)(data->content))->fd = fd;
		if (!(((t_fddata *)(data->content))->buf = ft_memalloc(BUFF_SIZE)))
			r = -1;
	}
	fdl = (t_fddata *)(data->content);
	while (!fdl->eof && r >= 0)
	{
		if ((r = alloc_and_move(fdl, line)) == 1)
			return (1);
		if (r >= 0)
			if ((r = parse_read(read(fd, fdl->buf, BUFF_SIZE), fdl, line)) > 0)
				return (1);
	}
	return (remove_data(&root, fd, r));
}
