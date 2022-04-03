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

t_vector2 ft_add_vector(t_vector2 v1, t_vector2 v2)
{
	t_vector2	ret;

	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	return (ret);
}