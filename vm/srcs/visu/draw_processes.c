/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:29:04 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 11:29:06 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "vm.h"

static void		draw_process(t_process *pr, t_vis *vis, t_ulong *map)
{
	SDL_Rect	rect;
	t_uint		elem;
	t_uint		bit;

	elem = pr->pc / (sizeof(t_ulong) * 8);
	bit = pr->pc % (sizeof(t_ulong) * 8);
	if (!(map[elem] & (1u << bit)))
	{
		rect.x = START_FIELD_X + (pr->pc % 64) * vis->cur_font.width * 2 +
			(pr->pc % 64) * vis->cur_font.width / 2;
		rect.y = START_FIELD_Y + (pr->pc / 64) * vis->cur_font.height;
		rect.w = vis->cur_font.width * 2;
		rect.h = vis->cur_font.height;
		SDL_RenderCopy(vis->ren,
			vis->carriages[pr->player_id - 1], NULL, &rect);
		map[elem] |= (1u << bit);
	}
}

void			draw_processes(t_vis *vis, t_vm *vm)
{
	t_process	*pr;
	t_ulong		map[MEM_SIZE / (sizeof(t_ulong) * 8)];

	ft_bzero(map, sizeof(map));
	pr = vm->processes_root;
	while (pr)
	{
		if (pr->pc >= 0 && pr->pc < MEM_SIZE)
			draw_process(pr, vis, map);
		pr = pr->next;
	}
}
