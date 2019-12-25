/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 10:59:51 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 10:59:52 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		recalc_room_size(t_vis *vis, int w, int h)
{

}


int			process_event(t_vis *vis)
{
	int			run;
	SDL_Event	e;

	run = 1;
	if (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			run = 0;
		else if (e.type == SDL_WINDOWEVENT)
		{
			if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				recalc_room_size(vis, e.window.data1, e.window.data2);
		}
	}
	return (run);
}