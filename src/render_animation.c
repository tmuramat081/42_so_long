#include "so_long.h"
#include <time.h>

void	set_next_animation_image(int *slide)
{
	static int i;

	if (i % 3 == 0)
	{
		*slide += 1;
		if (*slide == 4)
			*slide = 0;
	}
	i++;
}

void draw_lerp_position(t_game *game, t_clist *character, float time)
{
	t_vector2 start;
	t_vector2 end;
	void 		*img;
	t_vector2 tmp;

	img = game->img.player[character->dir][character->slide];			
	start = ft_vector_mul(character->pos, GRID_SIZE);
	end = ft_vector_mul(ft_vector_add(character->pos, character->vector), GRID_SIZE);
	if (character->anim_pos.x || character->anim_pos.y)
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor, character->anim_pos.x, character->anim_pos.y);
	tmp = ft_vector_lerp(start, end, time / 0.5f);
	mlx_put_image_to_window(game->mlx, game->win, img, tmp.x, tmp.y);
}

void	render_moving_animation(t_game *game, t_clist *character)
{
	t_timespec	current;
	double	passed;

	if (character->anim_time.tv_sec == 0)
		timespec_get(&character->anim_time, TIME_UTC);
	timespec_get(&current, TIME_UTC);
	passed = ft_diff_timespec(&character->anim_time, &current);
	printf("%f\n", passed);
	if (passed > 0.5f)
	{
		character->pos =  ft_vector_add(character->pos, character->vector);
		character->vector = (t_vector2){0, 0};
		character->anim_time = (t_timespec){};
		return ;
	}
	draw_lerp_position(game, character, passed);
}

void 	render_standing_animation(t_game *game, t_clist *character)
{
	void *img;

	if (character->type == TYPE_PLAYER)
		img = game->img.player[character->dir][character->slide];
	else	
		img = game->img.enemy[character->dir][character->slide];
	set_next_animation_image(&character->slide);
	put_image_to_window(game, img, character->pos);
	character = character->next;
	return ;
}

void	render_animation(t_game *game, t_clist *player)
{
	if (player->vector.x || player->vector.y)
		render_moving_animation(game, player);
	else
		render_standing_animation(game, player);
}
