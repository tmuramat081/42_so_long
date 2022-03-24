#include "so_long.h"

void	init_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 1000, 400, WINDOW_TITLE);
	render_map(game);
	set_hook(game);
}