/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:03:34 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 11:03:35 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "vm.h"
#include "ft_printf.h"
#include <SDL2_gfxPrimitives.h>

static void			draw_text(t_vis *vis, int x, int y, t_ushort val)
{
	SDL_Rect		rect;
	t_uint			player;

	player = val >> 8u < 5 ? val >> 8u : 0;
	rect.x = x;
	rect.y = y;
	rect.w = vis->cur_font.width;
	rect.h = vis->cur_font.height;
	SDL_RenderCopy(vis->ren,
		vis->glyph_textures[player][(val >> 4u) & 0xFu], NULL, &rect);
	rect.x = x + vis->cur_font.width;
	rect.y = y;
	rect.w = vis->cur_font.width;
	rect.h = vis->cur_font.height;
	SDL_RenderCopy(vis->ren,
		vis->glyph_textures[player][val & 0xFu], NULL, &rect);
}

static void			draw_field(t_vis *vis, t_vm *vm)
{
	int			x;
	int			y;
	int			px;
	int 		py;

	y = -1;
	while (++y < 64)
	{
		x = -1;
		while (++x < 64)
		{
			px = START_FIELD_X + x * vis->cur_font.width * 2 +
				x * vis->cur_font.width / 2;
			py = START_FIELD_Y + y * vis->cur_font.height;
			draw_text(vis, px, py, vm->field[y * 64 + x]);
		}
	}
}


SDL_Color	get_color(int r, int g, int b, int a)
{
	SDL_Color	color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void				draw_cycles(t_vis *vis, t_vm *vm)
{
	SDL_Point	xy;
	char 		buf[64];
	SDL_Color	color;

	xy.x = START_FIELD_X + 64 * vis->cur_font.width * 2
		   + 64 * vis->cur_font.width / 2 + 10;
	xy.y = START_FIELD_Y + 10 * vis->cur_font.width;
	ft_sprintf(buf, "Cycles: %zu", vm->cycles);
	color = get_color(68, 113, 82, 255);
	text_out(vis, &xy, buf, color);
}

void				draw_max_processes(t_vis *vis, t_vm *vm)
{
	SDL_Point xy;
	char	  buf[64];
	SDL_Color color;

	xy.x = START_FIELD_X + 64 * vis->cur_font.width * 2
		   + 64 * vis->cur_font.width / 2 + 10;
	xy.y = START_FIELD_Y + 12 * vis->cur_font.width;
	ft_sprintf(buf, "Processes: %zu", vm->process_max);
	color = get_color(68, 113, 82, 255);
	text_out(vis, &xy, buf, color);
}

Uint32				get_uint32_color(int r, int g, int b, int a)
{
	Uint32	color;

	color = ((Uint32)a & 0xFFu) << 24u;
	color |= ((Uint32)b & 0xFFu) << 16u;
	color |= ((Uint32)g & 0xFFu) << 8u;
	color |= ((Uint32)r & 0xFFu);
	return (color);
}

void				draw_borders(t_vis *vis)
{
	roundedRectangleColor(vis->ren,
		1,
		1,
		START_FIELD_X + 64 * vis->cur_font.width * 2
		+ 64 * vis->cur_font.width / 2 + 1,
		START_FIELD_Y + 64 * vis->cur_font.height +1 ,
		10,
		get_uint32_color(49, 51, 53, 255));
}

void 				draw_processes(t_vis *vis, t_vm *vm)
{
	t_process	*pr;
	SDL_Rect	rect;
	t_ulong		map[MEM_SIZE / (sizeof(t_ulong) * 8)];
	t_uint 		elem;
	t_uint 		bit;

	ft_bzero(map, sizeof(map));
	pr = vm->processes_root;
	while (pr)
	{
		if (pr->pc >=0 && pr->pc < MEM_SIZE)
		{
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
		pr = pr->next;
	}
}

void				draw_all(t_vis *vis, t_vm *vm)
{
	SDL_SetRenderDrawColor(vis->ren, 0, 0, 0, 0xFF);
	SDL_RenderClear(vis->ren);
	draw_borders(vis);
	draw_processes(vis, vm);
	draw_field(vis, vm);
	draw_cycles(vis, vm);
	draw_max_processes(vis, vm);
	SDL_RenderPresent(vis->ren);
}
