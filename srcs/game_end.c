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

#include "so_long.h"

void	free_animation_images(t_game *game, t_img *img)
{
	int i;
	int j;

	i = 0;
	while (i < DIR_END)
	{
		j = 0;
		while (j < NUM_FRAMES)
		{
			mlx_destroy_image(game->mlx, img->player[i][j]);
			mlx_destroy_image(game->mlx, img->enemy[i][j]);
			j++;
		}
		i++;
	}
}

void	free_counter_images(t_game *game, t_img *img)
{
	int i;

	i = 0;
	while (i < 10)
	{
		mlx_destroy_image(game->mlx, img->digit[i]);
		i++;
	}
}

void	free_images(t_game *game, t_img *img)
{
	mlx_destroy_image(game->mlx, img->back);
	mlx_destroy_image(game->mlx, img->wall);
	mlx_destroy_image(game->mlx, img->collect);
	mlx_destroy_image(game->mlx, img->exit);
	mlx_destroy_image(game->mlx, img->menu);
	mlx_destroy_image(game->mlx, img->logo);
	mlx_destroy_image(game->mlx, img->title);
	free_counter_images(game, img);
	free_animation_images(game, img);
}



int	close_window(t_game *game, char *message)
{
	(void)message;
	put_steps(game);
	ft_free_matrix(&game->map);
	character_lstclear(&game->character);
	free_images(game, &game->img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	check_game_state(t_game *game, t_clist *character)
{
	bool	is_any_moving;
	bool	is_any_playing;

	is_any_moving = false;
	is_any_playing = false;
	while (character)
	{
		if (character->type == TYPE_PLAYER)
		{
			if (character->vector.x || character->vector.y)
				is_any_moving = true;
			is_any_playing = true;
		}
		character = character->next;
	}
	if (game->is_key_pressed == true && is_any_moving == false)
	{
		put_steps(game);
		game->is_key_pressed = false;
	}
	if (is_any_playing == false)
		close_window (game, WIN_GAME);
}
