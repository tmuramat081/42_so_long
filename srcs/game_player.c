/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:25:24 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:25:24 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check what's ahead of the player, then rewrite own coordinates. */
void	set_player_dir(t_clist *character, t_dir dir)
{
	while (character)
	{
		if (character->type == TYPE_PLAYER)
		{
			character->dir = dir;
			if (dir == DIR_DOWN)
				character->vector = (t_vector2){0, 1};
			else if (dir == DIR_UP)
				character->vector = (t_vector2){0, -1};
			else if (dir == DIR_LEFT)
				character->vector = (t_vector2){-1, 0};
			else if (dir == DIR_RIGHT)
				character->vector = (t_vector2){1, 0};
		}
		character = character->next;
	}
}

/* Set to call functions when keyboard is pressed. */
int	check_key_entry(int keycode, t_game *game)
{
	if (game->is_key_locked == true)
		return (0);
	if (keycode == KEY_Q || keycode == KEY_ESC)
	{
		put_end_message(EXIT_GAME);
		exit_game_normally(game);
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
		set_player_dir(game->character, DIR_LEFT);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		set_player_dir(game->character, DIR_RIGHT);
	else if (keycode == KEY_W || keycode == KEY_UP)
		set_player_dir(game->character, DIR_UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		set_player_dir(game->character, DIR_DOWN);
	game->is_key_locked = true;
	return (0);
}
