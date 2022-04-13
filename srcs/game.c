/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:38:34 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/13 00:38:34 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

const double	g_frame_time = 1.0 / FPS_MAX;

/* Limit max FPS(Frame Per Second), using usleep function. */
void	limit_frame_rate(t_timespec *start_time)
{
	t_timespec	current_time;
	double		took_time;
	double		wait_time;

	clock_gettime(CLOCK_REALTIME, &current_time);
	took_time = ft_diff_timespec(start_time, &current_time);
	if (g_frame_time > took_time)
	{
		wait_time = (g_frame_time - took_time) * 1000000;
		usleep(wait_time);
	}
}

int	update_game(t_game *game)
{
	t_timespec	start_time;

	clock_gettime(CLOCK_REALTIME, &start_time);
	char_lstiter(game, &set_enemy_move);
	char_lstiter(game, &detect_object_collision);
	char_lstiter(game, &detect_character_collision);
	check_game_state(game, game->character);
	char_lstiter(game, &render_animation);
	limit_frame_rate(&start_time);
	game->frame++;
	if (game->frame == NUM_FRAMES * LTD_FRAMES)
		game->frame = 0;
	return (0);
}

/* Hook functions in mlx loop. */
void	set_game_hooks(t_game *game)
{
	mlx_hook(game->win, 02, 1L << 0, check_key_entry, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_expose_hook (game->win, render_frame, game);
	mlx_do_key_autorepeatoff (game->mlx);
}
