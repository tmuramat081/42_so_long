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

/* Check what's ahead of player, then rewrite own coordinates. */
void move_player(t_game *game, int next_x, int next_y)
{
	void *img;
	int prev_x;
	int prev_y;

	img = game->img.floor;
	prev_x = game->player_coord.x;
	prev_y = game->player_coord.y;

	if (exist_wall(game->map[next_y][next_x]) == true)
		return ;
	else if (exist_exit(game->map[next_y][next_x], game) == true)
		return ;
	else if (exist_dot(game->map[next_y][next_x]) == true)
	{
		game->map[next_y][next_x] = '0';
		game->rem_dot -= 1;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, prev_x * GRID_SIZE, prev_y * GRID_SIZE);
	game->player_coord.x = next_x;
	game->player_coord.y = next_y;
	put_steps(game);
}

/* Call functions when keyboard is pressed. */
int check_key_entry(int keycode, t_game *game)
{
	int x;
	int y;

	x = game->player_coord.x;
	y = game->player_coord.y;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, x-1, y);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, x+1, y);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, x, y-1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, x, y+1);
	else if (keycode == KEY_Q || keycode == KEY_ESC)
		close_window(game);
//	printf("KEYCODE:%d\n", keycode);
	return (0);
}

/* Hook functions in mlx loop. */
void set_events(t_game *game)
{
	mlx_expose_hook (game->win, render_map, game);
	mlx_expose_hook (game->win, render_footer, game);
	mlx_hook(game->win, 02, 1L<<0, check_key_entry, game);
	mlx_loop_hook(game->mlx, render_player, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_do_key_autorepeatoff(game->mlx);
}
