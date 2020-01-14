/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 08:59:35 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/25 08:59:35 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <SDL.h>
# include <SDL_ttf.h>
# include "op.h"

# define FIELD_FONT		"monaco.ttf"

# define START_FIELD_X	(10)
# define START_FIELD_Y	(10)

typedef enum {
	ALL,
	USUAL,
	FRESH
}	t_process_highlight;

typedef struct		s_wh
{
	int		width;
	int		height;
}					t_wh;

typedef struct		s_vis
{
	SDL_Window		*window;
	SDL_Renderer	*ren;
	TTF_Font		*field_font;
	int				wwidth;
	int				wheight;
	t_wh			font100;
	t_wh			cur_font;
	SDL_Texture		*glyph_textures[MAX_PLAYERS * 2 + 2][16];
	SDL_Texture		*carriages[MAX_PLAYERS * 2];
	SDL_Rect		info_box;
}					t_vis;

void				print_sdl_error(const char *err);
int					init_sdl(t_vis *vis);
void				sdl_destroy(t_vis *vis);
void				destroy_glyph_textures(t_vis *vis);
void				destroy_carriages_textures(t_vis *vis);

SDL_Color			get_color(int r, int g, int b, int a);
Uint32				get_uint32_color(int r, int g, int b, int a);
int					reload_font(t_vis *vis);
void				text_out(t_vis *vis, SDL_Point *xy, const char *txt,
						SDL_Color color);
SDL_Color			get_process_color(int id, t_process_highlight prh);
Uint32				get_uint32_process_color(int id, t_process_highlight prh);
void				init_carriages(t_vis *vis);
#endif
