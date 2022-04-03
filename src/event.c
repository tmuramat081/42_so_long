#include "so_long.h"

int 	close_window(t_game *game)
{
	put_steps(game);
	put_end_message(game);
	ft_free_matrix(&game->map);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

/* Check what's ahead of the player, then rewrite own coordinates. */
void move_player(t_game *game, t_vector2 vector, t_stat stat)
{
	t_vector2 prev;
	t_vector2 next;

	game->p_stat = stat;
	prev = game->player_coord;
	next = ft_add_vector(prev, vector);
	if (exist_wall(game->map[next.y][next.x]) == true)
		return ;
	else if (exist_exit(game->map[next.y][next.x], game) == true)
		return ;
	else if (exist_dot(game->map[next.y][next.x]) == true)
	{
		game->map[next.y][next.x] = '0';
		game->cnt_dot -= 1;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.floor, prev.x * GRID_SIZE, prev.y * GRID_SIZE);
	game->player_coord = next;
	put_steps(game);
}

/* Set to call functions when keyboard is pressed. */
int check_key_entry(int keycode, t_game *game)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, (t_vector2){-1, 0}, STAT_LEFT);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, (t_vector2){1, 0}, STAT_RIGHT);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, (t_vector2){0, -1}, STAT_UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, (t_vector2){0, 1}, STAT_DOWN);
	return (0);
}




/* Hook functions in mlx loop. */
void set_events(t_game *game)
{
	mlx_expose_hook (game->win, render_frame, game);
	mlx_hook(game->win, 02, 1L<<0, check_key_entry, game);
	mlx_loop_hook(game->mlx, render_player, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_do_key_autorepeatoff(game->mlx);

}
