/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:22:03 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:22:03 by tmuramat         ###   ########.fr       */
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
const char	*g_enemy_directory[4] = {
	XPM_ENEMY_DOWN,
	XPM_ENEMY_UP,
	XPM_ENEMY_LEFT,
	XPM_ENEMY_RIGHT,
};

void	load_character_frames(t_game *game, void **img, const char *directory)
{
	char	file_path[PATH_MAX];
	int		i;

	i = 0;
	while (i < NUM_FRAMES)
	{
		ft_snprintf(file_path, sizeof(file_path), "%s%d.xpm", directory, i);
		img[i] = xpm_file_to_image(game->mlx, file_path, GRID_SIZE);
		i++;
	}
}

void	load_animation(t_game *game)
{
	int	i;

	i = 0;
	while (i < DIR_END)
	{
		load_character_frames(game, game->img.player[i], g_player_directory[i]);
		load_character_frames(game, game->img.enemy[i], g_enemy_directory[i]);
		i++;
	}
}
