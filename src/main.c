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
			mlx_put_image_to_window(game->mlx, game->win, game->img.floor, j * TIP_SIZE, i * TIP_SIZE);
			j++;
		}
		i++;
	}
}


int	main (int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		exit(1);
	init_game(&game);
	load_image_file(&game);
	game.map = load_map_file(argv[1]);
	draw_back(&game);
	draw_map(&game);

	game.player_pos.x = 3;
	game.player_pos.y = 3;
	set_hook(&game);
	mlx_loop(game.mlx);
	return (0);
}