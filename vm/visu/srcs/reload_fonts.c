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

static int	get_pt_size(t_vis *vis)
{
	int ptw;
	int	pth;

	ptw = (vis->wwidth - 40) / (64 * 2 + 64 / 2 + 64);
	pth = (vis->wheight - 20) / (64);
	ptw = ptw * 100 / vis->font100.width;
	pth = pth * 100 / vis->font100.height;
	return (ft_min(pth, ptw));
}

int 		load_font(t_vis *vis)
{
	if (vis->field_font)
		TTF_CloseFont(vis->field_font);
	vis->field_font = TTF_OpenFont(FIELD_FONT, get_pt_size(vis));
	if (vis->field_font == NULL)
	{
		print_sdl_error(TTF_GetError());
		return (1);
	}
	TTF_SizeText(vis->field_font, "X",
		&vis->cur_font.width, &vis->cur_font.height);
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
