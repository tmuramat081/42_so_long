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

void	render_character(t_game *game)
{
	void *img;
	int x;
	int y;

	img = game->img.player;
	x = game->player_coord.x;
	y = game->player_coord.y;
	mlx_put_image_to_window(game->mlx, game->win, img, x * GRID_SIZE, y * GRID_SIZE);
}

void	render_map(t_game *game)
{
	int		i;
	int 	j;
	void	*img;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 30)
		{
			img = get_grid_image(i, j, game);
			mlx_put_image_to_window(game->mlx, game->win, img, j * GRID_SIZE, i *GRID_SIZE);
			j++;
		}
		i++;
	}
}
