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

void	render_moving_animation(t_game *game, t_clist *character)
{
	void 		*img;
	t_vector2	start;
	t_vector2	end;
	t_vector2 	tmp;
	while (character)
	{
		if (character->is_moving == true)
		{
			img = game->img.player[character->dir][character->slide];
			start = character->draw_pos;
			end = ft_vector_scalar_mul(character->next_pos, GRID_SIZE);
			mlx_put_image_to_window(game->mlx, game->win, game->img.floor, character->draw_pos.x, character->draw_pos.y);
			tmp = ft_vector_lerp(start, end, 0.1);
			mlx_put_image_to_window(game->mlx, game->win, img, tmp.x, tmp.y);
		}
		character = character->next;
	}
}

void 	render_standing_animation(t_game *game, t_clist *character)
{
	void *img;
	t_vector2 draw_pos;

	while (character)
	{
		if (character->type == TYPE_PLAYER)
			img = game->img.player[character->dir][character->slide];
		else	
			img = game->img.enemy[character->dir][character->slide];
		set_next_animation_image(&(character->slide));
		draw_pos = ft_vector_scalar_mul(character->pos, GRID_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
		character = character->next;
	}
	return ;
}
