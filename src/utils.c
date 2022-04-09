#include "so_long.h"

void put_image_to_window(t_game *game, void *img, t_vector2 pos)
{
	t_vector2 draw_pos;

	draw_pos = ft_vector_scalar_mul(pos, GRID_SIZE);
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

t_vector2 ft_vector_add(t_vector2 v1, t_vector2 v2)
{
	t_vector2	ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	return (ret);
}

t_vector2 ft_vector_sub(t_vector2 v1, t_vector2 v2)
{
	t_vector2	ret;

	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	return (ret);
}

t_vector2 ft_vector_scalar_mul(t_vector2 v1, float t)
{
	t_vector2	ret;

	ret.x = (float)v1.x * t;
	ret.y = (float)v1.y * t;
	return (ret);
}


t_vector2 ft_vector_lerp(t_vector2 v1, t_vector2 v2, float t) 
{
	t_vector2 ret;
	
	ret.x = (1.0f - t) * (float)v1.x + t * (float)v2.x;
	ret.y = (1.0f - t) * (float)v1.y + t * (float)v2.y;
	return (ret);
}