#include "so_long.h"

void	move_animation(t_game game, t_coord *prev)
{
	static floot move_coef = 0.7;
	static int move_amt = GRID_SIZE;
	void	*img;
	
	img = game->img.floor;
	mlx_put_image_to_window(game->mlx, game->win, img, prev_x * GRID_SIZE, prev_y * GRID_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, img, prev_x * GRID_SIZE + 1, prev_y * GRID_SIZE);
}