/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:20:51 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:20:51 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_snprintf.h"

const char	*g_player_directory[4] = {
	XPM_PLAYER_DOWN,
	XPM_PLAYER_UP,
	XPM_PLAYER_LEFT,
	XPM_PLAYER_RIGHT,
};

void	load_character_images(t_game *game)
{
	char	path[PATH_MAX];
	int		i;

	i = 0;
	while (i < DIR_END)
	{
		ft_snprintf(path, sizeof(path), "%s%d.xpm", g_player_directory[i], 0);
		game->img.player[i] = xpm_file_to_image(game, path, GRID_SIZE);
		i++;
	}
}

void	load_object_images(t_game *game)
{
	game->img.back = xpm_file_to_image(game, XPM_BACK, GRID_SIZE);
	game->img.wall = xpm_file_to_image(game, XPM_WALL, GRID_SIZE);
	game->img.collect = xpm_file_to_image(game, XPM_COLLECT, GRID_SIZE);
	game->img.exit = xpm_file_to_image(game, XPM_EXIT, GRID_SIZE);
}

void	load_images(t_game *game)
{
	load_object_images(game);
	load_character_images(game);
}
