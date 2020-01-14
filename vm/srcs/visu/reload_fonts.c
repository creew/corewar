/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_fonts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:33:34 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 09:33:35 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "visu.h"
#include <SDL2_gfxPrimitives.h>

static int		get_pt_size(t_vis *vis)
{
	double	ptw;
	double	pth;

	ptw = (vis->wwidth - 40.0) / (64 * 2 + 64 / 2.0 + 32);
	pth = (vis->wheight - 20.0) / (64);
	ptw = ptw * 100 / vis->font100.width;
	pth = pth * 100 / vis->font100.height;
	return (ft_min((int)pth, (int)ptw));
}

static void		init_glyphs(t_vis *vis)
{
	size_t			i;
	size_t			j;
	SDL_Surface		*surface;

	destroy_glyph_textures(vis);
	i = -1;
	while (++i < (sizeof(vis->glyph_textures) / sizeof(vis->glyph_textures[0])))
	{
		j = -1;
		while (++j < (sizeof(vis->glyph_textures[0]) /
			sizeof(vis->glyph_textures[0][0])))
		{
			surface = TTF_RenderGlyph_Blended(vis->field_font,
				(j > 9 ? (j - 10 + 'a') : (j + '0')),
				get_process_color(i, ALL));
			vis->glyph_textures[i][j] =
				SDL_CreateTextureFromSurface(vis->ren, surface);
			SDL_FreeSurface(surface);
		}
	}
}

int				reload_font(t_vis *vis)
{
	if (vis->field_font)
		TTF_CloseFont(vis->field_font);
	vis->field_font = TTF_OpenFont(FIELD_FONT, get_pt_size(vis));
	if (vis->field_font == NULL)
	{
		print_sdl_error(TTF_GetError());
		return (1);
	}
	TTF_SetFontHinting(vis->field_font, TTF_HINTING_MONO);
	TTF_SizeText(vis->field_font, "X",
		&vis->cur_font.width, &vis->cur_font.height);
	init_glyphs(vis);
	init_carriages(vis);
	vis->info_box.x = START_FIELD_X + 64 * vis->cur_font.width * 2
		+ 64 * vis->cur_font.width / 2 + 10;
	vis->info_box.y = START_FIELD_Y;
	return (0);
}

void			text_out(t_vis *vis, SDL_Point *xy, const char *txt,
	SDL_Color color)
{
	SDL_Surface		*surface;
	SDL_Texture		*msg;
	SDL_Rect		rect;

	surface = TTF_RenderUTF8_Solid(vis->field_font, txt, color);
	msg = SDL_CreateTextureFromSurface(vis->ren, surface);
	rect.x = xy->x;
	rect.y = xy->y;
	rect.w = surface->w;
	rect.h = surface->h;
	SDL_RenderCopy(vis->ren, msg, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(msg);
}
