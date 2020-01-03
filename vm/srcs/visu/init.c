/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 08:53:04 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 08:53:04 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "visu.h"

static int	create_renderer(t_vis *vis)
{
	vis->ren = SDL_CreateRenderer(vis->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (vis->ren == NULL)
	{
		print_sdl_error(SDL_GetError());
		return (1);
	}
	SDL_SetRenderDrawColor(vis->ren, 0x00, 0xFF, 0x00, 0xFF);
	return (0);
}

static int	create_window(t_vis *vis)
{
	vis->window = SDL_CreateWindow("Corewar",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		vis->wwidth,
		vis->wheight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (vis->window == NULL)
	{
		print_sdl_error("SDL_CreateWindow");
		return (1);
	}
	SDL_SetWindowMinimumSize(vis->window, 1000, 600);
	return (0);
}

static int	calc_font(t_vis *vis)
{
	TTF_Font *font;

	font = TTF_OpenFont(FIELD_FONT, 100);
	if (font == NULL)
	{
		print_sdl_error(TTF_GetError());
		return (1);
	}
	TTF_SizeText(font, "X", &vis->font100.width, &vis->font100.height);
	TTF_CloseFont(font);
	return (0);
}

int			init_sdl(t_vis *vis)
{
	ft_bzero(vis, sizeof(*vis));
	vis->wwidth = 2000;
	vis->wheight = 1400;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0)
	{
		print_sdl_error("Init");
		return (1);
	}
	if (create_window(vis) != 0)
		return (1);
	if (create_renderer(vis) != 0)
		return (1);
	if (TTF_Init() != 0)
	{
		print_sdl_error(TTF_GetError());
		return (1);
	}
	if (calc_font(vis) != 0)
		return (1);
	reload_font(vis);
	return (0);
}