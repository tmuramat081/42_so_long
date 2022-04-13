/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:14:15 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:14:15 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

void	init_game(t_game *game)
{
	size_t	win_width;
	size_t	win_height;

	win_width = game->map_width * GRID_SIZE;
	win_height = (game->map_height + 1) * GRID_SIZE;
	game->win = mlx_new_window(game->mlx, win_width, win_height, WINDOW_TITLE);
	load_images(game);
	set_game_hooks(game);
	render_frame(game);
	put_steps(game);
	srand(time(NULL));
}

void	input_map(t_game *game, char *map_file)
{
	if (is_valid_file_name(map_file) == false)
		put_error_and_exit(ERR_FILE_NAME);
	load_map_file(map_file, game);
	if (!game->map)
		put_error_and_exit(ERR_FILE_READ);
	else if (!*game->map)
		put_error_and_exit(ERR_MAP_EMPTY);
	char_lstiter(game, &validate_map_playability, TYPE_PLAYER);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		put_error_and_exit(ERR_ARGS);
	game = (t_game){};
	game.mlx = mlx_init();
	input_map(&game, argv[1]);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
