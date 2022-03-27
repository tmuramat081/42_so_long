#include "so_long.h"

void	*get_grid_image(int y, int x, t_game *game)
{
	void *img;

	if (game->map[y][x] == '1')
		img = game->img.wall;
	else if (game->map[y][x] == 'C')
		img = game->img.dot;
	else if (game->map[y][x] == 'E')
		img = game->img.exit;
	else
		img = game->img.floor;
	return (img);
}

int	render_player(t_game *game)
{
	void *img;
	int x;
	int y;

	img = game->img.player;
	x = game->player_coord.x;
	y = game->player_coord.y;
	mlx_put_image_to_window(game->mlx, game->win, img, x * GRID_SIZE, y * GRID_SIZE);
	return (0);
}

void	render_map(t_game *game)
{
	size_t	i;
	size_t 	j;
	void	*img;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			img = get_grid_image(i, j, game);
			mlx_put_image_to_window(game->mlx, game->win, img, j * GRID_SIZE, i *GRID_SIZE);
			j++;
		}
		i++;
	}
}
