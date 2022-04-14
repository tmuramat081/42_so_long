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

#include "so_long_bonus.h"

void	should_lock_key(t_game *game, t_clist *character)
{
	if (character->vector.x || character->vector.y)
		game->is_key_locked = true;
}

void	check_game_state(t_game *game)
{
	size_t		ret;
	static bool	is_step_counted;

	game->is_key_locked = false;
	ret = char_lstiter(game, should_lock_key, TYPE_PLAYER);
	if (is_step_counted == false && game->is_key_locked == true)
	{
		put_steps(game);
		is_step_counted = true;
	}
	else if (game->is_key_locked == false)
		is_step_counted = false;
	if (ret == 0)
	{
		put_end_message(WIN_GAME);
		exit_game_normally(game);
	}
}
