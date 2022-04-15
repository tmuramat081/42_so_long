/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:02:47 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/14 15:02:47 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(t_game *game, t_clist *character)
{
	if (character->vector.x || character->vector.y)
	{
		put_image_to_window(game, game->img.back, character->pos);
		character->pos = ft_vector_add(character->pos, character->vector);
		character->vector = (t_vector2){0, 0};
		game->is_any_moved = true;
	}
}

void	check_game_state(t_game *game)
{
	size_t	player_cnt;

	player_cnt = char_lstiter(game, update_position, TYPE_PLAYER);
	if (game->is_any_moved == true)
		put_steps(game);
	if (player_cnt == 0)
	{
		put_end_message(WIN_GAME);
		exit_game_normally(game);
	}
	game->is_any_moved = false;
}
