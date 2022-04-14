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

#include "so_long_bonus.h"
#include <time.h>

void	handle_process_error(t_game *game, char *message)
{
	put_error_message(message);
	if (game)
		free_game_buffer(game);
	exit(EXIT_FAILURE);
}

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
		handle_process_error(game, ERR_FILE_NAME);
	load_map_file(map_file, game);
	if (!game->map)
		handle_process_error(game, ERR_FILE_READ);
	else if (!*game->map)
		handle_process_error(game, ERR_MAP_EMPTY);
	if (char_lstiter(game, &validate_map_playability, TYPE_PLAYER) == 0)
		handle_process_error(game, ERR_PLAYERS);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		handle_process_error(NULL, ERR_ARGS);
	game = (t_game){};
	game.mlx = mlx_init();
	input_map(&game, argv[1]);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
