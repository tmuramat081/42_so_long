#include "so_long.h"
#include "time.h"

const double	g_frame_time = 1.0 / FPS_MAX;

bool is_legal_move(t_game *game, t_vector2 next)
{
	char **map;

	map = game->map;
	if (map[next.y][next.x] == '1')
		return (false);
	else if (map[next.y][next.x] == 'E')
	{
		if (game->cnt_dot == 0)
			close_window(game);
		return (false);
	}
	else if (map[next.y][next.x] == 'C')
	{
		game->map[next.y][next.x] = '0';
		game->cnt_dot -= 1;
	}
	return (true);
}

/* Check what's ahead of the player, then rewrite own coordinates. */
void set_player_move(t_game *game, t_vector2 vector, t_dir dir)
{
	t_clist *player;
	t_vector2 next_pos;

	player = game->player;
	while (player)
	{
		player->vector = vector;
		player->dir = dir;
		next_pos = ft_vector_add(player->pos, player->vector);
		if (is_legal_move(game, next_pos) == false)
			break ;
		player->is_moving = true;
		put_steps(game);
		player = player->next;
	}
}

/* Set to call functions when keyboard is pressed. */
int check_key_entry(int keycode, t_game *game)
{
	if (game->player->is_moving == true)
		return (0);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		set_player_move(game, (t_vector2){-1, 0}, DIR_LEFT);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		set_player_move(game, (t_vector2){1, 0}, DIR_RIGHT);
	else if (keycode == KEY_W || keycode == KEY_UP)
		set_player_move(game, (t_vector2){0, -1}, DIR_UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		set_player_move(game, (t_vector2){0, 1}, DIR_DOWN);
	return (0);
}

/* Limit FPS_MAX(Frame Per Second), using usleep function. */
void	limit_frame_rate(clock_t start_time)
{
	double	took_time;
	static double wait_time;

	took_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
	if (g_frame_time > took_time)
	{
		wait_time = (g_frame_time - took_time) * 1000000;
		usleep(wait_time);	
	}
}

int	update_game(t_game *game)
{
	clock_t start_time;

	start_time = clock();
	if (game->player->is_moving == true)
		render_moving_animation(game);
	else
		render_standing_animation(game);
	limit_frame_rate(start_time);
	return (0);
}

/* Hook functions in mlx loop. */
void set_events(t_game *game)
{
	mlx_hook(game->win, 02, 1L<<0, check_key_entry, game);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_expose_hook (game->win, render_frame, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_do_key_autorepeatoff(game->mlx);
}
