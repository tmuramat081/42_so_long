#include "so_long.h"

t_clist	*target_exists(t_vector2 pos, t_vector2 next_pos, t_clist *target)
{
	while(target)
	{
		if (ft_vector_cmp(pos, target->pos) == false &&
			ft_vector_cmp(next_pos, ft_vector_add(target->pos, target->vector)) == true)
			return (target);
		target = target->next;
	}
	return (NULL);
}

void	detect_character_collision(t_game *game, t_clist	*character)
{
	t_vector2	next_pos;
	t_clist		*target;

	if (character->vector.x == 0 && character->vector.y == 0)
		return ;
	next_pos = ft_vector_add(character->pos, character->vector);
	target = target_exists(character->pos, next_pos, character);
	if (!target)
		return ;
	else if (target->type != character->type)
		close_window(game);
	else if (target->type == character->type)
		detect_character_collision(game, target);
	character->vector = (t_vector2){};
}
