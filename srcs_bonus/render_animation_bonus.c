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

#include "so_long_bonus.h"
#include <time.h>

void	*get_animation_image(t_game *game, t_clist *character)
{
	void	*img;
	short	frame;

	frame = game->frame / LTD_FRAMES;
	if (character->type == TYPE_PLAYER)
		img = game->img.player[character->dir][frame];
	else if (character->type == TYPE_ENEMY_L)
		img = game->img.enemy_l[character->dir][frame];
	else if (character->type == TYPE_ENEMY_S)
		img = game->img.enemy_s[character->dir][frame];
	else
		img = game->img.back;
	return (img);
}

/* Calculate intermediate point between A and B, using linear interpolation. */
t_vector2	calculate_lerp_position(t_clist *character, float time)
{
	t_vector2	start;
	t_vector2	end;

	start = ft_vector_mul(character->pos, GRID_SIZE);
	end = ft_vector_mul(ft_vector_add(character->pos, \
		character->vector), GRID_SIZE);
	return (ft_vector_lerp(start, end, time / MOVE_DURATION));
}

/* If moving duration is passed, rewirite character's position. */
void	update_current_position(t_game *game, t_clist *character)
{
	put_image_to_window(game, game->img.back, character->pos);
	character->pos = ft_vector_add(character->pos, character->vector);
	character->vector = (t_vector2){0, 0};
	character->anim_start = (t_timespec){};
	return ;
}

/* Draw animation at the specified time. */
void	render_moving_animation(t_game *game, t_clist *character, void *img)
{
	t_timespec	current;
	double		passed;
	t_vector2	draw_pos;

	if (character->anim_start.tv_sec == 0)
		clock_gettime(CLOCK_REALTIME, &character->anim_start);
	clock_gettime(CLOCK_REALTIME, &current);
	passed = ft_diff_timespec(&character->anim_start, &current);
	if (passed > MOVE_DURATION)
		update_current_position(game, character);
	if (character->anim_pos.x || character->anim_pos.y)
		mlx_put_image_to_window(game->mlx, game->win, game->img.back, \
			character->anim_pos.x, character->anim_pos.y);
	draw_pos = calculate_lerp_position(character, passed);
	mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
}

void	render_animation(t_game *game, t_clist *character)
{
	void	*img;

	img = get_animation_image(game, character);
	if (character->vector.x || character->vector.y)
		render_moving_animation(game, character, img);
	else
		put_image_to_window(game, img, character->pos);
}
