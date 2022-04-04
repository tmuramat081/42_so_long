#include "so_long.h"

int 	close_window(t_game *game)
{
	put_steps(game);
	put_end_message(game);
	ft_free_matrix(&game->map);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
