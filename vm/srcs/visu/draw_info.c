/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklompus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:21:49 by eklompus          #+#    #+#             */
/*   Updated: 2019/12/28 19:21:49 by eklompus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf.h"

static void		draw_info_string(t_vis *vis, const char *str, int index,
	SDL_Color color)
{
	SDL_Point	xy;

	xy.x = vis->info_box.x;
	xy.y = vis->info_box.y + index * vis->cur_font.height;
	text_out(vis, &xy, str, color);
}

static void		draw_state(t_vis *vis, t_vm *vm)
{
	SDL_Color	color;
	char		*s;
	char		buf[64];

	if (vm->state == RUNNING)
		s = "** RUNNING **";
	else if (vm->state == PAUSED)
		s = "** PAUSED **";
	else
		s = "** FINISHED **";
	color = get_color(68, 113, 82, 255);
	draw_info_string(vis, s, 0, color);
	ft_sprintf(buf, "Processes: %zu", vm->process_max);
	color = get_color(68, 113, 82, 255);
	draw_info_string(vis, buf, 11, color);
	ft_sprintf(buf, "Cycles: %d", vm->cycles);
	color = get_color(68, 113, 82, 255);
	draw_info_string(vis, buf, 9, color);
}

static int		draw_player_info(t_vis *vis, t_vm *vm)
{
	size_t		i;
	t_player	*player;
	int 		start_index;
	char	  	buf[32];
	SDL_Color	color;

	color = get_color(255, 255, 255, 255);
	start_index = 13;
	i = -1;
	while (++i < vm->count_players)
	{
		player = vm->players[i];
		ft_snprintf(buf, sizeof(buf), "Player -%d : %s", player->player_id,
			player->name);
		draw_info_string(vis, buf, start_index, get_process_color(player->player_id - 1, USUAL));
		ft_snprintf(buf, sizeof(buf), "  Last live : %zu", player->last_live);
		draw_info_string(vis, buf, ++start_index, color);
		ft_snprintf(buf, sizeof(buf), "  Lives in current period : %zu",
			player->live_in_session);
		draw_info_string(vis, buf, ++start_index, color);
		start_index += 2;
	}
	return (start_index);
}

static int		draw_cycle_info(t_vis *vis, t_vm *vm, int start_index)
{
	char	  	buf[64];
	SDL_Color	color;

	color = get_color(68, 113, 82, 255);
	ft_snprintf(buf, sizeof(buf), "CYCLE_TO_DIE: %d", vm->cycle_to_die);
	draw_info_string(vis, buf, start_index, color);
	start_index += 2;
	ft_snprintf(buf, sizeof(buf), "CYCLE_DELTA: %d", CYCLE_DELTA);
	draw_info_string(vis, buf, start_index, color);
	start_index += 2;
	ft_snprintf(buf, sizeof(buf), "NBR_LIVE: %d", NBR_LIVE);
	draw_info_string(vis, buf, start_index, color);
	start_index += 2;
	ft_snprintf(buf, sizeof(buf), "MAX_CHECKS: %d", MAX_CHECKS);
	draw_info_string(vis, buf, start_index, color);
	start_index += 2;
	return (start_index);
}

void			draw_info(t_vis *vis, t_vm *vm)
{
	int		last_index;

	draw_state(vis, vm);
	last_index = draw_player_info(vis, vm);
	draw_cycle_info(vis, vm, last_index);
}
