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

#include "so_long_bonus.h"
#include "ft_snprintf.h"

const char	*g_player_dir[4] = {
	XPM_PLAYER_DOWN,
	XPM_PLAYER_UP,
	XPM_PLAYER_LEFT,
	XPM_PLAYER_RIGHT,
};
const char	*g_enemy_l_dir[4] = {
	XPM_ENEMY_L_DOWN,
	XPM_ENEMY_L_UP,
	XPM_ENEMY_L_LEFT,
	XPM_ENEMY_L_RIGHT,
};

const char	*g_enemy_s_dir[4] = {
	XPM_ENEMY_S_DOWN,
	XPM_ENEMY_S_UP,
	XPM_ENEMY_S_LEFT,
	XPM_ENEMY_S_RIGHT,
};

void	load_character_frames(t_game *game, void **img, const char *directory)
{
	char	file_path[PATH_MAX];
	int		i;

	i = 0;
	while (i < NUM_FRAMES)
	{
		ft_snprintf(file_path, sizeof(file_path), "%s%d.xpm", directory, i);
		img[i] = xpm_file_to_image(game, file_path, GRID_SIZE);
		i++;
	}
}

void	load_animation(t_game *game)
{
	int	i;

	i = 0;
	while (i < DIR_END)
	{
		load_character_frames(game, game->img.player[i], g_player_dir[i]);
		load_character_frames(game, game->img.enemy_l[i], g_enemy_l_dir[i]);
		load_character_frames(game, game->img.enemy_s[i], g_enemy_s_dir[i]);
		i++;
	}
}
