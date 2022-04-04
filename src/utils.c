#include "so_long.h"

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

t_vector2 ft_vector_scalar_mul(t_vector2 v1, int t)
{
	t_vector2	ret;

	ret.x = v1.x * t;
	ret.y = v1.y * t;
	return (ret);
}


t_vector2 ft_vector_lerp(t_vector2 v1, t_vector2 v2, float t) 
{
	t_vector2	diff;
	t_vector2 ret;
	
	diff.x = v1.x - v2.x;
	diff.y = v2.y - v2.y;
	ret.x = v1.x + (float)diff.x * t;
	ret.y = v1.y + (float)diff.y * t;
	return (ret);
}