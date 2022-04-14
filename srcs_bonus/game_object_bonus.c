/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:46:07 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/13 12:46:07 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	wall_exists(t_game *game, t_vector2 next)
{
	if (game->map[next.y][next.x] == '1')
	{
		return (true);
	}
	return (false);
}

bool	exit_exists(t_game *game, t_vector2 next)
{
	if (game->map[next.y][next.x] == 'E')
	{
		return (true);
	}
	return (false);
}

bool	collective_exists(t_game *game, t_vector2 next)
{
	if (game->map[next.y][next.x] == 'C')
	{
		game->map[next.y][next.x] = '0';
		return (true);
	}
	return (false);
}

void	manage_object_event(t_game *game, t_clist *character)
{
	t_vector2	next_pos;

	next_pos = ft_vector_add(character->pos, character->vector);
	if (wall_exists(game, next_pos) == true)
		character->vector = (t_vector2){};
	else if (collective_exists(game, next_pos) == true)
		game->cnt_collect -= 1;
	else if (exit_exists(game, next_pos) == true)
	{
		if (game->cnt_collect == 0)
		{
			character->type = TYPE_NONE;
			put_image_to_window(game, game->img.back, character->pos);
		}
		character->vector = (t_vector2){};
	}
}
