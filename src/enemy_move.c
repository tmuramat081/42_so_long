# include "so_long.h"

bool	check_hit_enemy(t_game *game, t_vector2 player_pos)
{
	while (enemy)
	{
		if (ft_vector_cmp(player_pos, enemy_pos) == true)
			return (true);
		next = enemy->next;
	}
	return (false);
}

void set_enemy_move(t_game *game)
{
	t_dir dir;

	srand((unsigned int)time(NULL));
	while (enemy)
	{
		if (enemy->is_moving == FALSE)
		{
			dir = rund() % DIR_END + 1;
			set_player_dir(enemy, dir);
		}
		enemy = enemy->next;
	}
}