#include "so_long.h"

t_clist	*target_exists(t_vector2 pos, t_vector2 next_pos, t_clist *target)
{
	while(target)
	{
		if (ft_vector_cmp(pos, target->pos) == false && target->type != TYPE_NONE && ft_vector_cmp(next_pos, target->pos) == true)
			return (target);
		target = target->next;
	}
	return (NULL);
}

void	detect_character_collision(t_game *game, t_clist	*character)
{
	t_vector2	next_pos;
	t_clist		*target;

	if (!character)
		return ;
	if (character->vector.x == 0 && character->vector.y == 0)
		return ;
	next_pos = ft_vector_add(character->pos, character->vector);
	target = target_exists(character->pos, next_pos, game->character);
	detect_character_collision(game, target);
	if (target && (target->vector.x == 0 && target->vector.y == 0))
		character->vector = (t_vector2){};
}

bool exist_wall(t_game *game, t_vector2 next)
{
	if (game->map[next.y][next.x] == '1')
	{
		return (true);
	}
	return (false);
}

bool	exist_exit(t_game *game, t_vector2 next)
{
	if (game->map[next.y][next.x] == 'E')
	{
		return (true);
	}
	return (false);
}

bool	exist_collective(t_game *game, t_vector2 next)
{
	if (game->map[next.y][next.x] == 'C')
	{
		game->map[next.y][next.x] = '0';
		return (true);
	}
	return (false);
}

void	detect_object_collision(t_game *game, t_clist *character)
{
	t_vector2 next_pos;

	next_pos = ft_vector_add(character->pos, character->vector);
	if (exist_wall(game, next_pos) == true)
		character->vector = (t_vector2){};
	else if (exist_collective(game, next_pos) == true)
		game->cnt_dot -= 1;
	else if (exist_exit(game, next_pos) == true)
	{
		if (game->cnt_dot == 0)
		{
			character->type = TYPE_NONE;
			put_image_to_window(game, game->img.floor, character->pos);
		}
		character->vector = (t_vector2){};
	}
}