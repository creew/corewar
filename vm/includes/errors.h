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
#define ERRORS_H

typedef int t_result;


#define RET_OK					(0)
#define ERR_OPEN_CHAMP			(-1)
#define ERR_READ_CHAMP			(-2)
#define ERR_WRONG_MAGIC			(-3)
#define ERR_CHAMP_TO_BIG		(-4)
#define ERR_ENOMEM				(-5)
#define ERR_READ_BODY_CHAMP		(-6)

#endif
