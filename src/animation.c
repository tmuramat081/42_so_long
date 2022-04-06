#include "so_long.h"

void	set_next_animation_image(int *slide)
{
	*slide += 1;
	if (*slide == 4)
}

void	render_moving_animation(t_game *game)
{
	static int move = 0;
	static t_vector2 draw_pos;
	void *img;

	if (!move)
		draw_pos = ft_vector_scalar_mul(game->player->pos, GRID_SIZE);
	if (move == GRID_SIZE)
	{
		move = 0;
		game->player->is_moving = false;
		game->player->pos = ft_vector_add(game->player->pos, game->player->vector);
		return ;
	}
	img = game->img.player[game->player->dir][game->player->slide];
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, draw_pos.x, draw_pos.y);
	draw_pos = ft_vector_add(draw_pos, game->player->vector);
	mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
	move++;
}

void 	render_standing_animation(t_game *game)
{
	void *img;
	t_vector2 draw_pos;

	img = game->img.player[game->player->dir][game->player->slide];
	set_next_animation_image(&(game->player->slide));
	draw_pos = ft_vector_scalar_mul(game->player->pos, GRID_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
	return ;
}