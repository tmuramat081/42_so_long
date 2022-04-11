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

void	check_hit(t_game *game, t_clist	*character)
{
	t_vector2	next_pos;
	t_clist		*target;

	if (character->vector.x == 0 && character->vector.y == 0)
		return ;
	next_pos = ft_vector_add(character->pos, character->vector);
	target = target_exists(character->pos, next_pos, game->player);
	if (!target)
		return ;
	else if (target->type == TYPE_ENEMY)
		close_window(game);
	else if (target->type == TYPE_PLAYER)
		check_hit(game, target);
	puts("OK");
	character->vector = (t_vector2){};
}
