#include "so_long.h"

void	init_game_info(t_game *game)
{
	game = (t_game *)malloc (sizeof(t_game));
	game->img = malloc (sizeof(t_img));
	game->player_pos = malloc (sizeof(t_pos));
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1000, 400, WINDOW_TITLE);
	init_game_info(game);
}