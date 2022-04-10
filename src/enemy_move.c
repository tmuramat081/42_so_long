# include "so_long.h"

void	random_horizontal_move(t_clist *enemy)
{
	short	direction;

	direction = rand() % 3;
	if (direction == 0)
	{
		enemy->dir = DIR_LEFT;
		enemy->vector = (t_vector2){-1, 0};
	}
	else if (direction == 1)
	{
		enemy->dir = DIR_RIGHT;
		enemy->vector = (t_vector2){1, 0};
	}
	else
	{
		
	}
}

void set_enemy_move(t_game *game)
{
	t_clist *enemy;

	enemy = game->enemy;
	while (enemy)
	{
		if (enemy->vector.x == 0 && enemy->vector.y == 0)
			random_horizontal_move(enemy);
		enemy = enemy->next;
	}
}