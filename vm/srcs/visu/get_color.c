/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:17:22 by eklompus          #+#    #+#             */
/*   Updated: 2020/01/14 09:17:23 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static const SDL_Color g_colors[] = {
	{85, 85, 85, 255},
	{255, 255, 255, 255},
	{0, 185, 0, 255},
	{0, 0, 185, 255},
	{185, 0, 0, 255},
	{0, 185, 185, 255},
	{85, 255, 85, 255},
	{85, 85, 255, 255},
	{255, 85, 85, 255},
	{85, 255, 255, 255}
};

SDL_Color		get_process_color(int id, t_process_highlight prh)
{
	if (prh == ALL)
	{
		if (id < (int)(sizeof(g_colors) / sizeof(g_colors[0])))
			return (g_colors[id]);
	}
	else if (id >= 1 && id <= MAX_PLAYERS)
	{
		if (prh == USUAL)
			return (g_colors[id + 1]);
		if (prh == FRESH)
			return (g_colors[id + MAX_PLAYERS + 1]);
	}
	return (g_colors[0]);
}

Uint32			get_uint32_color(int r, int g, int b, int a)
{
	Uint32	color;

	color = ((Uint32)a & 0xFFu) << 24u;
	color |= ((Uint32)b & 0xFFu) << 16u;
	color |= ((Uint32)g & 0xFFu) << 8u;
	color |= ((Uint32)r & 0xFFu);
	return (color);
}

Uint32			get_uint32_process_color(int id, t_process_highlight prh)
{
	SDL_Color	color;

	color = get_process_color(id, prh);
	return (get_uint32_color(color.r, color.g, color.b, color.a));
}
