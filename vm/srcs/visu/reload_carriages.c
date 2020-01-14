/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_carriages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:42:58 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 11:43:01 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include <SDL2_gfxPrimitives.h>

static void		init_carriage(t_vis *vis, SDL_Texture **target,
	Uint32 back, Uint32 border)
{
	*target = SDL_CreateTexture(vis->ren, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET,
		vis->cur_font.width * 2 + 1,
		vis->cur_font.height + 1);
	SDL_SetRenderTarget(vis->ren, *target);
	SDL_SetRenderDrawColor(vis->ren, 0, 0, 0, 0);
	SDL_RenderClear(vis->ren);
	roundedBoxColor(vis->ren, 0, 0, vis->cur_font.width * 2,
		vis->cur_font.height, 3, back);
	roundedRectangleColor(vis->ren, 0, 0, vis->cur_font.width * 2,
		vis->cur_font.height, 3, border);
	SDL_SetRenderTarget(vis->ren, NULL);
}

void			init_carriages(t_vis *vis)
{
	int		i;
	Uint32	color;

	color = get_uint32_color(255, 255, 255, 180);
	destroy_carriages_textures(vis);
	i = -1;
	while (++i < MAX_PLAYERS)
		init_carriage(vis, &vis->carriages[i],
			color, get_uint32_process_color(i + 1, USUAL));
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		color = get_uint32_process_color(i + 1, USUAL);
		init_carriage(vis, &vis->carriages[i + MAX_PLAYERS],
			color, color);
	}
}
