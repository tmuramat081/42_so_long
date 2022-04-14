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

#define TITLE_WIDTH 7

void	render_steps(size_t num, t_game *game)
{
	size_t		y_offset;
	static int	x;
	void		*img;

	y_offset = game->map_height;
	img = game->img.digit[num % 10];
	if (num / 10)
		render_steps(num / 10, game);
	else
		x = 1;
	put_image_to_window(game, img, (t_vector2){x, y_offset});
	x++;
}

void	render_footer(t_game *game)
{
	size_t	y_offset;
	t_img	img;
	size_t	x;

	img = game->img;
	y_offset = game->map_height;
	put_image_to_window(game, img.logo, (t_vector2){0, y_offset});
	x = 1;
	while (x < game->map_width)
	{
		put_image_to_window(game, img.menu, (t_vector2){x, y_offset});
		if (x + TITLE_WIDTH == game->map_width)
		{
			put_image_to_window(game, img.title, (t_vector2){x, y_offset});
			break ;
		}
		x++;
	}
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

void	render_map(t_game *game)
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
}

int	render_frame(t_game *game)
{
	render_map(game);
	render_footer(game);
	render_steps(0, game);
	return (0);
}
