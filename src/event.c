#include "so_long.h"

/* Check what's ahead of the player, then rewrite own coordinates. */
void set_player_move(t_game *game, t_vector2 vector, t_stat state)
{
	t_clist *player;
	t_vector2 next;

	player = game->player;
	player->state = state;
	player->vector = vector;
	next = ft_vector_add(player->pos, player->vector);
	if (exist_wall(game->map[next.y][next.x]) == true)
		return ;
	else if (exist_exit(game->map[next.y][next.x], game) == true)
		return ;
	else if (exist_dot(game->map[next.y][next.x]) == true)
	{
		game->map[next.y][next.x] = '0';
		game->cnt_dot -= 1;
	}
	player->is_moving = true;
	put_steps(game);
}

/* Set to call functions when keyboard is pressed. */
int check_key_entry(int keycode, t_game *game)
{
	if (game->player->is_moving == true)
		return (0);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		set_player_move(game, (t_vector2){-1, 0}, STAT_LEFT);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		set_player_move(game, (t_vector2){1, 0}, STAT_RIGHT);
	else if (keycode == KEY_W || keycode == KEY_UP)
		set_player_move(game, (t_vector2){0, -1}, STAT_UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		set_player_move(game, (t_vector2){0, 1}, STAT_DOWN);
	return (0);
}

int	update_game(t_game *game)
{
	t_clist	*player;

	player = game->player;
	if (player->is_moving == true)
		render_moving_animation(game);
	else
		render_standing_animation(game);
	usleep(2000);
	return (0);
}


/* Hook functions in mlx loop. */
void set_events(t_game *game)
{
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_hook(game->win, 02, 1L<<0, check_key_entry, game);
	mlx_expose_hook (game->win, render_frame, game);
	mlx_hook(game->win, 17, 0, close_window, game);
//	mlx_do_key_autorepeatoff(game->mlx);
}
