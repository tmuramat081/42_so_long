#include "so_long.h"

void put_image_to_window(t_game *game, void *img, t_vector2 pos)
{
	t_vector2 draw_pos;

	draw_pos = ft_vector_mul(pos, GRID_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
}

bool exist_wall(char grid)
{
	if (grid == '1')
		return (true);
	return (false);
}

bool exist_exit(char grid, t_game *game)
{
	if (grid == 'E')
	{
		if (game->cnt_dot == 0)
			close_window(game);
		return (true);
	}
	return (false);
}

bool exist_dot(char grid)
{
	if (grid == 'C')
		return (true);
	return (false);
}
