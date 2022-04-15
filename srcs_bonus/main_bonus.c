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

void	handle_error(t_game *game, char *message)
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

void	input_map(t_game *game, char *file_name)
{
	size_t	player_cnt;

	if (is_valid_file_name(file_name) == false)
		handle_error(game, ERR_FILE_NAME);
	load_map_file(file_name, game);
	if (!game->map)
		handle_error(game, ERR_FILE_READ);
	else if (!*game->map)
		handle_error(game, ERR_MAP_EMPTY);
	parse_map(game);
	player_cnt = char_lstiter(game, &validate_map_playability, TYPE_PLAYER);
	if (player_cnt == 0)
		handle_error(game, ERR_NO_PLAYER);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		handle_error(NULL, ERR_ARGS);
	game = (t_game){};
	game.mlx = mlx_init();
	input_map(&game, argv[1]);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
