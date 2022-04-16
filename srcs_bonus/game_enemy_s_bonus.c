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

#include "so_long_bonus.h"

int	search_closest_player(int col, t_clist *target)
{
	int	diff_min;

	diff_min = INT_MAX;
	while (target)
	{
		if (target->type == TYPE_PLAYER)
		{
			if (ft_abs(diff_min) > ft_abs(target->pos.x - col))
				diff_min = target->pos.x - col;
		}
		target = target->next;
	}
	return (diff_min);
}

t_dir	turn_eyes(t_game *game, t_clist *character)
{
	int		diff;

	diff = search_closest_player(character->pos.x, game->character);
	if (diff < 0)
		return (DIR_LEFT);
	return (DIR_RIGHT);
}

void	set_enemy_s_dir(t_game *game, t_clist *character)
{
	t_dir	direction;

	direction = turn_eyes(game, character);
	character->dir = direction;
}
