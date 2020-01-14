/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_carriages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:29:04 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 11:29:06 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "vm.h"

void			draw_carriage(t_vis *vis, int col, int row, int pid)
{
	SDL_Rect	rect;

	rect.x = START_FIELD_X + col * vis->cur_font.width * 2 +
		col * vis->cur_font.width / 2;
	rect.y = START_FIELD_Y + row * vis->cur_font.height;
	rect.w = vis->cur_font.width * 2;
	rect.h = vis->cur_font.height;
	SDL_RenderCopy(vis->ren,
		vis->carriages[pid - 1], NULL, &rect);
}

void			draw_carriages(t_vis *vis, t_vm *vm)
{
	t_process	*pr;
	t_uint		elem;
	t_uint		bit;
	t_ulong		map[MEM_SIZE / (sizeof(t_ulong) * 8)];

	ft_bzero(map, sizeof(map));
	pr = vm->processes_root;
	while (pr)
	{
		if (pr->pc >= 0 && pr->pc < MEM_SIZE)
		{
			elem = pr->pc / (sizeof(t_ulong) * 8);
			bit = pr->pc % (sizeof(t_ulong) * 8);
			if (!(map[elem] & (1u << bit)))
			{
				draw_carriage(vis, pr->pc % 64, pr->pc / 64, pr->player_id);
				map[elem] |= (1u << bit);
			}
		}
		pr = pr->next;
	}
}
