#include "so_long.h"

bool	is_hit_character(t_vector2 pos, t_vector2 next_pos, t_clist *opponent)
{
	t_vector2 opponent_next;

	while(opponent)
	{ 
		opponent_next = ft_vector_add(opponent->pos, opponent->vector);
		if (ft_vector_cmp(pos, opponent->pos) == false && ft_vector_cmp(next_pos, opponent_next) == true)
			return (true);
		opponent = opponent->next;
	}
	return (false);
}

void	check_hit(t_game *game, t_clist	*character)
{
	t_vector2	pos;
	t_vector2	next_pos;

	pos = character->pos;
	next_pos = ft_vector_add(pos, character->vector);
	if (is_hit_character(pos, next_pos, game->player) == true)
		character->vector = (t_vector2){};
}
