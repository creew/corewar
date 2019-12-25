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

#include "visu.h"
#include "libft.h"

const SDL_Color g_colors[] = {
	{104, 104, 100, 255},
	{180, 48, 27, 255},
	{0, 255, 0, 255},
	{0, 0, 255, 255},
	{255, 255, 0, 255},
};

static int	get_pt_size(t_vis *vis)
{
	int ptw;
	int	pth;

	ptw = (vis->wwidth - 40) / (64 * 2 + 64 / 2 + 32);
	pth = (vis->wheight - 20) / (64);
	ptw = ptw * 100 / vis->font100.width;
	pth = pth * 100 / vis->font100.height;
	return (ft_min(pth, ptw));
}

void		init_glyphs(t_vis *vis)
{
	int				i;
	int				j;
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
				(j > 9 ? (j - 10 + 'a') : (j + '0')), g_colors[i]);
			vis->glyph_textures[i][j] =
				SDL_CreateTextureFromSurface(vis->ren, surface);
			SDL_FreeSurface(surface);
		}
	}
}

int			reload_font(t_vis *vis)
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
	return (0);
}

void		text_out(t_vis *vis, SDL_Point *xy, char *txt, SDL_Color color)
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
