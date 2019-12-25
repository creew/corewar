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

#include <SDL2_gfxPrimitives.h>

const SDL_Color g_colors[] = {
	{104, 104, 100, 255},
	{180, 48, 27, 255},
	{0, 255, 0, 255},
	{0, 0, 255, 255},
	{255, 255, 0, 255},
};

static char			half_byte_to_char(t_uint hc)
{
	hc &= 0xFu;
	return ((char)(hc > 9 ? (hc - 10 + 'a') : (hc + '0')));
}

static SDL_Color	get_field_text(char *buf, t_ushort val)
{
	t_uint		player;

	buf[0] = half_byte_to_char(val >> 4u);
	buf[1] = half_byte_to_char(val);
	buf[2] = '\0';
	if ((player = val >> 8u) != 0)
	{
		if (player >= 1 && player <= 4)
			return (g_colors[player]);
	}
	return (g_colors[0]);
}

static void			draw_field(t_vis *vis, t_vm *vm)
{
	int			x;
	int			y;
	SDL_Point	xy;
	char		buf[8];
	SDL_Color	color;

	y = -1;
	while (++y < 64)
	{
		x = -1;
		while (++x < 64)
		{
			xy.x = START_FIELD_X + x * vis->cur_font.width * 2 +
				x * vis->cur_font.width / 2;
			xy.y = START_FIELD_Y + y * vis->cur_font.height;
			color = get_field_text(buf, vm->field[y * 64 + x]);
			text_out(vis, &xy, buf, color);
		}
	}
}

Uint32		get_uint32_color(int r, int g, int b, int a)
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

void				draw_all(t_vis *vis, t_vm *vm)
{

	SDL_SetRenderDrawColor(vis->ren, 0, 0, 0, 0xFF);
	SDL_RenderClear(vis->ren);
	draw_borders(vis);
	draw_field(vis, vm);
	SDL_RenderPresent(vis->ren);
}
