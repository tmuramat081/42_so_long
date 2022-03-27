#include "so_long.h"
#include "ft_printf.h"

int 	close_window(t_game *game)
{
	ft_free_matrix(&game->map);
	if (game->rem_dot == 0)
		ft_printf(WIN_GAME);
	else
		ft_printf(EXIT_GAME);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}