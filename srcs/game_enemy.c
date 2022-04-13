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
#include <time.h>

void	eat_glass(t_clist *character)
{
	character->vector = (t_vector2){0, 0};
}

void	go_straight(t_clist *character)
{
	if (character->dir == DIR_LEFT)
	{
		character->dir = DIR_LEFT;
		character->vector = (t_vector2){-1, 0};
	}
	else
	{
		character->dir = DIR_RIGHT;
		character->vector = (t_vector2){1, 0};
	}
}

void	turn_around(t_clist *character)
{
	if (character->dir == DIR_LEFT)
	{
		character->dir = DIR_RIGHT;
		character->vector = (t_vector2){1, 0};
	}
	else
	{
		character->dir = DIR_LEFT;
		character->vector = (t_vector2){-1, 0};
	}
}

void	set_enemy_dir(t_game *game, t_clist *character)
{
	t_vector2	next;

	if (character->vector.x || character->vector.y)
		return ;
	else if (rand() % 10 > ENEMY_LEVEL)
		eat_glass(character);
	else
		go_straight(character);
	next = ft_vector_add(character->pos, character->vector);
	if (game->map[next.y][next.x] == '1'
		|| game->map[next.y][next.x] == 'C'
		|| game->map[next.y][next.x] == 'E')
		turn_around(character);
}
