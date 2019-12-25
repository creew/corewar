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

void 		sdl_destroy(t_vis *vis)
{
	SDL_DestroyWindow(vis->window);
	vis->window = NULL;
	SDL_DestroyRenderer(vis->ren);
	vis->ren = NULL;
	TTF_CloseFont(vis->field_font);
	vis->field_font = NULL;
	SDL_Quit();
	TTF_Quit();
}
