/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wrapper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:09:20 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:09:20 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_game *game, void *img, t_vector2 pos)
{
	t_vector2	draw_pos;

	draw_pos = ft_vector_mul(pos, GRID_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
}

void	*xpm_file_to_image(void *mlx, char *img_file, int size)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, img_file, &img_width, &img_height);
	if (img == NULL || (size && (img_height != size || img_width != size)))
		put_error_and_exit(ERR_FILE_FMT);
	return (img);
}

void	char_lstiter(t_game *game, void (*func)(t_game *, t_clist *), t_typ type)
{
	t_clist	*character;

	character = game->character;
	if (!character)
		return ;
	while (character)
	{
		if (character->type & type)
			func(game, character);
		character = character->next;
	}
}
