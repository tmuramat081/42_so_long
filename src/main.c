#include "so_long.h"

int	main (int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		put_error_and_exit("ERROR");
	game.mlx = mlx_init();
	input_map(&game, argv[1]);
	input_image(&game);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
