/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:35:02 by eklompus          #+#    #+#             */
/*   Updated: 2019/10/11 12:35:03 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*pf_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*to;
	const unsigned char	*from;
	size_t				count;

	from = (const unsigned char *)src;
	to = (unsigned char *)dst;
	if (from == to)
		return (dst);
	count = 0;
	while (count < n)
	{
		to[count] = from[count];
		count++;
	}
	return (dst);
}

void	fp_write_c(void **param, char *data, size_t len)
{
	(void)param;
	write(1, data, len);
}

void	s_write_c(void **param, char *data, size_t len)
{
	char	*s;

	s = (char *)*param;
	pf_memcpy(s, data, len);
	s[len] = '\0';
	*param = s + len;
}

void	sn_write_c(void **param, char *data, size_t len)
{
	t_snparam *par;

	par = *param;
	if (len > par->size)
		len = par->size;
	if (len <= par->size && len)
	{
		pf_memcpy(par->s, data, len);
		par->s += len;
		*par->s = '\0';
		par->size -= len;
	}
}

void	fp_write_fd(void **param, char *data, size_t len)
{
	int *fd;

	fd = *param;
	write(*fd, data, len);
}
