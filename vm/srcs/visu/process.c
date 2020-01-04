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

#include "vm.h"
#include "ft_printf.h"

void		recalc_room_size(t_vis *vis, t_vm *vm, int w, int h)
{
	vis->wwidth = w;
	vis->wheight = h;
	reload_font(vis);
	draw_all(vis, vm);
}

void		process_keyboard(SDL_KeyboardEvent *e, t_vis *vis, t_vm *vm)
{
	(void)vis;
	if (e->keysym.sym == ' ')
		start_pause(vm);
	if (e->keysym.sym == 'a')
		vm->do_steps += 1;
	if (e->keysym.sym == 's')
		vm->do_steps += 10;
	if (e->keysym.sym == 'd')
		vm->do_steps += 100;
}

int			process_event(t_vis *vis, t_vm *vm)
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
				recalc_room_size(vis, vm, e.window.data1, e.window.data2);
		}
		else if (e.type == SDL_KEYDOWN)
		{
			process_keyboard(&e.key, vis, vm);
		}
	}
	return (run);
}