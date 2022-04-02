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
void move_player(t_game *game, t_coord next)
{
	void *img;
	t_coord prev;

	img = game->img.floor;
	prev = game->player_coord;
	if (exist_wall(game->map[next.y][next.x]) == true)
		return ;
	else if (exist_exit(game->map[next.y][next.x], game) == true)
		return ;
	else if (exist_dot(game->map[next.y][next.x]) == true)
	{
		game->map[next.y][next.x] = '0';
		game->cnt_dot -= 1;
	}
	mlx_put_image_to_window(game->mlx, game->win, img, prev.x * GRID_SIZE, prev.y * GRID_SIZE);
	game->player_coord.x = next.x;
	game->player_coord.y = next.y;
	put_steps(game);
}

/* Set to call functions when keyboard is pressed. */
int check_key_entry(int keycode, t_game *game)
{
	t_coord next_coord;

	next_coord = game->player_coord;
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->p_stat = STAT_LEFT;
		next_coord.x -= 1;
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->p_stat = STAT_RIGHT;
		next_coord.x += 1;
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->p_stat = STAT_UP;
		next_coord.y -= 1;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->p_stat = STAT_DOWN;
		next_coord.y += 1;
	}
	move_player(game, next_coord);
//	printf("KEYCODE:%d\n", keycode);
	return (0);
}

/* Hook functions in mlx loop. */
void set_events(t_game *game)
{
	mlx_expose_hook (game->win, render_frame, game);
	mlx_hook(game->win, 02, 1L<<0, check_key_entry, game);
	mlx_loop_hook(game->mlx, render_player, game);
	mlx_hook(game->win, 17, 0, close_window, game);
}
