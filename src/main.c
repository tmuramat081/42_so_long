#include "so_long.h"

int	main (int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		exit(1);
	init_game(&game);
	load_image_file(&game);
	game.map = load_map_file(argv[1]);
	draw_map(&game);
	set_hook(&game);
	mlx_loop(game.mlx);
	return (0);
}