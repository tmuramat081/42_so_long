/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:27:35 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 22:27:35 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_clist	*target_exists(t_vector2 pos, t_vector2 next_pos, t_clist *target)
{
	while (target)
	{
		if (target->type == TYPE_PLAYER
			&& ft_vector_cmp(pos, target->pos) == false
			&& ft_vector_cmp(next_pos, target->pos) == true)
			return (target);
		target = target->next;
	}
	return (NULL);
}

void	detect_character_collision(t_game *game, t_clist	*character)
{
	t_vector2	next_pos;
	t_clist		*target;

	next_pos = ft_vector_add(character->pos, character->vector);
	target = target_exists(character->pos, next_pos, game->character);
	if (!target)
		return ;
	else if (target->type != character->type)
	{
		put_end_message(LOSE_GAME);
		exit_game_normally(game);
	}
	detect_character_collision(game, target);
	if (target && (target->vector.x == 0 && target->vector.y == 0))
		character->vector = (t_vector2){};
}
