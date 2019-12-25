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
	ERR_ENOMEM,
	ERR_READ_BODY_CHAMP,
	ERR_TO_MUCH_PLAYERS,
	RET_OK = 0,
}	t_result;

#endif
