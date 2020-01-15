/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:34:28 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/24 13:34:29 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_MAXMIN		(-200)

typedef enum
{
	ERR_OPEN_CHAMP = ERR_MAXMIN,
	ERR_READ_CHAMP,
	ERR_WRONG_MAGIC,
	ERR_CHAMP_TO_BIG,
	ERR_CHAMP_ZEROSIZE,
	ERR_ENOMEM,
	ERR_READ_BODY_CHAMP,
	ERR_NO_ARGUMENTS,
	ERR_TO_LITTLE_PLAYERS,
	ERR_TO_MUCH_PLAYERS,
	ERR_INCORRECT_ORDER_PLAYERS,
	ERR_INCORRECT_DUMPARG,
	ERR_INCORRECT_NARG,
	ERR_INCORRECT_VARG,
	ERR_CANT_ASSIGN_INDEX,
	RET_OK = 0,
}	t_result;

typedef struct	s_errdesc
{
	t_result	res;
	char		*name;
}				t_errdesc;

char			*get_error(t_result err);
void			print_error(t_result res);
#endif
