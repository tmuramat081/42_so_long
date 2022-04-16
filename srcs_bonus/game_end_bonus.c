/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:44:22 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/13 00:44:22 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_animation_images(t_game *game, t_img img)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < DIR_END)
	{
		j = 0;
		while (j < NUM_FRAMES)
		{
			destroy_image(game->mlx, img.player[i][j]);
			destroy_image(game->mlx, img.enemy_l[i][j]);
			destroy_image(game->mlx, img.enemy_s[i][j]);
			j++;
		}
		i++;
	}
}

void	free_counter_images(t_game *game, t_img img)
{
	size_t	i;

	i = 0;
	while (i < 10)
	{
		destroy_image(game->mlx, img.digit[i]);
		i++;
	}
}

void	free_images(t_game *game)
{
	t_img	img;

	img = game->img;
	destroy_image(game->mlx, img.back);
	destroy_image(game->mlx, img.wall);
	destroy_image(game->mlx, img.collect);
	destroy_image(game->mlx, img.exit);
	destroy_image(game->mlx, img.menu);
	destroy_image(game->mlx, img.logo);
	destroy_image(game->mlx, img.title);
	free_counter_images(game, img);
	free_animation_images(game, img);
}

void	free_game_buffer(t_game *game)
{
	if (game->map)
		ft_free_matrix(&game->map);
	character_lstclear(&game->character);
	free_images(game);
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	exit_game_normally(t_game *game)
{
	free_game_buffer(game);
	exit(EXIT_SUCCESS);
	return (0);
}
