/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:43:54 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/13 00:43:54 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	random_horizontal_move(t_clist *enemy)
{
	short	direction;

	direction = rand() % 20;
	if (0 <= direction && direction < 3)
	{
		enemy->dir = DIR_LEFT;
		enemy->vector = (t_vector2){-1, 0};
	}
	else if (4 <= direction && direction < 7)
	{
		enemy->dir = DIR_RIGHT;
		enemy->vector = (t_vector2){1, 0};
	}
	else
	{
		enemy->vector = (t_vector2){0, 0};
	}
}

void	set_enemy_move(t_game *game, t_clist *character)
{
	(void)game;
	if (character->type == TYPE_ENEMY)
	{
		if (character->vector.x == 0 && character->vector.y == 0)
			random_horizontal_move(character);
	}
}
