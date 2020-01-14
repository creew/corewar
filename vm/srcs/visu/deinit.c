/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:06:50 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 09:06:50 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		destroy_carriages_textures(t_vis *vis)
{
	size_t i;

	i = -1;
	while (++i < (sizeof(vis->carriages) / sizeof(vis->carriages[0])))
	{
		SDL_DestroyTexture(vis->carriages[i]);
		vis->carriages[i] = NULL;
	}
}

void		destroy_glyph_textures(t_vis *vis)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < (sizeof(vis->glyph_textures) / sizeof(vis->glyph_textures[0])))
	{
		j = -1;
		while (++j < (sizeof(vis->glyph_textures[0]) /
			sizeof(vis->glyph_textures[0][0])))
		{
			SDL_DestroyTexture(vis->glyph_textures[i][j]);
			vis->glyph_textures[i][j] = NULL;
		}
	}
}

void		sdl_destroy(t_vis *vis)
{
	SDL_DestroyWindow(vis->window);
	vis->window = NULL;
	SDL_DestroyRenderer(vis->ren);
	vis->ren = NULL;
	TTF_CloseFont(vis->field_font);
	vis->field_font = NULL;
	destroy_glyph_textures(vis);
	destroy_carriages_textures(vis);
	SDL_Quit();
	TTF_Quit();
}
