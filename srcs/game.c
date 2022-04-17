/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:56:41 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/14 23:56:41 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game_normally(t_game *game)
{
	free_game_buffer(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int	update_game(t_game *game)
{
	char_lstiter(game, &manage_object_event, TYPE_PLAYER);
	char_lstiter(game, &detect_character_collision, TYPE_PLAYER);
	check_game_state(game);
	char_lstiter(game, &render_character, TYPE_PLAYER);
	return (0);
}

/* Hook functions in mlx loop. */
void	set_game_hooks(t_game *game)
{
	mlx_hook(game->win, 02, 1L << 0, input_key_entry, game);
	mlx_hook(game->win, 17, 0, exit_game_normally, game);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_expose_hook (game->win, render_map, game);
	mlx_do_key_autorepeatoff (game->mlx);
}
