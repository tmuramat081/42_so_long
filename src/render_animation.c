#include "so_long.h"

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
	t_clist *player;
	t_clist *enemy;
	void *img;
	t_vector2 draw_pos;

	player = game->player;
	enemy = game->enemy;
	while (player)
	{
		img = game->img.player[player->dir][player->slide];
		set_next_animation_image(&(player->slide));
		draw_pos = ft_vector_scalar_mul(player->pos, GRID_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
		player = player->next;
	}
	while (enemy)
	{
		img = game->img.enemy[enemy->dir][enemy->slide];
		set_next_animation_image(&(enemy->slide));
		draw_pos = ft_vector_scalar_mul(enemy->pos, GRID_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
		enemy = enemy->next;
	}
	return ;
}

/*
void *s_img
t_vector2 draw_pos
{
		img = game->img.player[character->dir][character->slide];
		set_next_animation_image(&(character->slide));
		draw_pos = ft_vector_scalar_mul(character->pos, GRID_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
	
}

	chracter_lstiter(game, player, render_standing_animation);
	chracter_lstiter(game, enemy, render_standing_animation);
*/