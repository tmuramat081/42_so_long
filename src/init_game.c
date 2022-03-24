#include "so_long.h"

void draw_back (t_game *game)
{
	int		i;
	int 	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 30)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img.floor, j * GRID_SIZE, i * GRID_SIZE);
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 1000, 400, WINDOW_TITLE);
	draw_back(game);
	draw_map(game);
	game->player_pos.x = 3;
	game->player_pos.y = 3;
	set_hook(game);
}