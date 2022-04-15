/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:26:51 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:26:51 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_character(t_game *game, t_clist *character)
{
	void	*img;

	img = game->img.player[character->dir];
	put_image_to_window(game, img, character->pos);
}

void	*get_object_image(int y, int x, t_game *game)
{
	void	*img;

	if (game->map[y][x] == '1')
		img = game->img.wall;
	else if (game->map[y][x] == 'C')
		img = game->img.collect;
	else if (game->map[y][x] == 'E')
		img = game->img.exit;
	else
		img = game->img.back;
	return (img);
}

int	render_map(t_game *game)
{
	size_t	x;
	size_t	y;
	void	*img;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			img = get_object_image(y, x, game);
			put_image_to_window(game, img, (t_vector2){x, y});
			x++;
		}
		y++;
	}
	return (0);
}
