/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:28:21 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:28:21 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

void	*get_animation_image(t_game *game, t_clist *character)
{
	void	*img;
	short	frame;

	frame = character->frame / 3;
	if (character->type == TYPE_PLAYER)
		img = game->img.player[character->dir][frame];
	else if (character->type == TYPE_ENEMY)
		img = game->img.enemy[character->dir][frame];
	else
		img = game->img.floor;
	character->frame += 1;
	if (character->frame / 3 == N_FRAMES)
		character->frame = 0;
	return (img);
}

void	draw_lerp_position(t_game *game, t_clist *character, float time)
{
	t_vector2	start;
	t_vector2	end;
	void		*img;
	t_vector2	tmp;

	img = get_animation_image(game, character);
	start = ft_vector_mul(character->pos, GRID_SIZE);
	end = ft_vector_mul(ft_vector_add(character->pos, character->vector), GRID_SIZE);
	if (character->anim_pos.x || character->anim_pos.y)
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, \
			character->anim_pos.x, character->anim_pos.y);
	tmp = ft_vector_lerp(start, end, time / MOVE_DUR);
	mlx_put_image_to_window(game->mlx, game->win, img, tmp.x, tmp.y);
}

void	render_moving_animation(t_game *game, t_clist *character)
{
	t_timespec	current;
	double		passed;

	if (character->anim_time.tv_sec == 0)
		clock_gettime(CLOCK_REALTIME, &character->anim_time);
	clock_gettime(CLOCK_REALTIME, &current);
	passed = ft_diff_timespec(&character->anim_time, &current);
	if (passed > MOVE_DUR)
	{
		put_image_to_window(game, game->img.floor, character->pos);
		character->pos = ft_vector_add(character->pos, character->vector);
		character->vector = (t_vector2){};
		character->anim_time = (t_timespec){};
		return ;
	}
	draw_lerp_position(game, character, passed);
}

void	render_standing_animation(t_game *game, t_clist *character)
{
	void	*img;

	img = get_animation_image(game, character);
	put_image_to_window(game, img, character->pos);
	return ;
}

void	render_animation(t_game *game, t_clist *character)
{
	if (character->vector.x || character->vector.y)
		render_moving_animation(game, character);
	else
		render_standing_animation(game, character);
}
