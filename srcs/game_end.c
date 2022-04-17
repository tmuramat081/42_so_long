/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:44:22 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/17 09:40:35 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_character_images(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < DIR_END)
	{
		destroy_image(game->mlx, game->img.player[i]);
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
	free_character_images(game);
}

#ifdef FOR_MAC
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
	free(game->mlx);
}
#else

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
#endif
