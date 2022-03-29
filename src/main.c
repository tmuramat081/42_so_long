#include "so_long.h"

void	init_game(t_game *game)
{
	size_t win_width;
	size_t win_height;

	win_width = game->map_width * GRID_SIZE;
	win_height = game->map_height * GRID_SIZE;
	game->win = mlx_new_window(game->mlx, win_width, win_height, WINDOW_TITLE);
	load_images(game);
	render_map(game);
	set_events(game);
	put_steps();
}

void input_map(t_game *game, char *map_file)
{
	char **map;

	if (is_valid_file_name(map_file) == false)
		put_error_and_exit(ERR_FILE_NAME);
	map = load_map_file(map_file);
	parse_map(map, game);
	check_is_playable_map(game, (const char **)map);
	game->map = map;
}

int	main (int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		put_error_and_exit(ERR_ARGS);
	game = (t_game){};
	game.mlx = mlx_init();
	input_map(&game, argv[1]);
	init_game(&game);
	mlx_loop(game.mlx);	
	return (0);
}
