/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:43:47 by eklompus          #+#    #+#             */
/*   Updated: 2019/09/21 20:08:34 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base(const char **nptr, int base)
{
	const char *ptr;

	ptr = *nptr;
	if ((base == 0 || base == 16) &&
		(ptr[0] == '0' && (ptr[1] == 'x' || ptr[1] == 'X')))
	{
		base = 16;
		*nptr = ptr + 2;
	}
	else if ((base == 0 || base == 8) && (ptr[0] == '0'))
		base = 8;
	else if (base == 0)
		base = 10;
	return (base);
}

static int	get_char_in_range(int c, int base)
{
	if (c >= '0' && c <= '9')
		c -= '0';
	else if (c >= 'a' && c <= 'z')
		c = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 10;
	else
		return (-1);
	if (c < base)
		return (c);
	return (-1);
}

static int	get_sign(const char **nptr)
{
	int			isneg;
	const char	*ptr;

	isneg = 1;
	ptr = *nptr;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			isneg = -1;
		*nptr = ptr + 1;
	}
	return (isneg);
}

static long	calc_val(long val, int num, int base, int *flow)
{
	if (val > FT_LONGMAX / base ||
		(val == FT_LONGMAX / base && num > FT_LONGMAX % base))
	{
		val = FT_LONGMAX;
		*flow = 1;
	}
	else if (val < (FT_LONGMIN / base) ||
		(val == (FT_LONGMIN / base) && num < (FT_LONGMIN % base)))
	{
		val = FT_LONGMIN;
		*flow = 1;
	}
	else
	{
		val *= base;
		val += num;
	}
	return (val);
}

long		ft_strtol(const char *nptr, char **endptr, int base)
{
	int		isneg;
	long	res;
	int		val;
	int		flow;

	res = 0;
	flow = 0;
	if (endptr)
		*endptr = (char *)nptr;
	while (ft_isspace(*nptr))
		nptr++;
	isneg = get_sign(&nptr);
	base = get_base(&nptr, base);
	if ((val = get_char_in_range(*nptr, base)) == -1)
		return (res);
	while (val != -1)
	{
		if (!flow)
			res = calc_val(res, val * isneg, base, &flow);
		val = get_char_in_range(*(++nptr), base);
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (res);
}
