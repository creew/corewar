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

#include "vm.h"
#include "visu.h"

const SDL_Color g_colors[] = {
	{0, 0, 0, 0},
	{255, 0, 0, 0},
	{0, 255, 0, 0},
	{0, 0, 255, 0},
	{255, 255, 0, 0},
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

void				draw_all(t_vis *vis, t_vm *vm)
{
	SDL_SetRenderDrawColor(vis->ren, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(vis->ren);
	draw_field(vis, vm);
	SDL_RenderPresent(vis->ren);
}
