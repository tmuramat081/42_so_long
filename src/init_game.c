#include "so_long.h"

void	init_game(t_game *game)
{
	size_t win_width;
	size_t win_height;

	win_width = game->map_width * GRID_SIZE;
	win_height = game->map_height * GRID_SIZE;
	game->win = mlx_new_window(game->mlx, win_width, win_height, WINDOW_TITLE);
	render_map(game);
	render_character(game);
	set_events(game);
}
