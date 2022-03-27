#include "so_long.h"

int render_next_frame(t_game *game)
{
	void *img;
	int x;
	int y;

	img = game->img.player;
	x = game->player_coord.x;
	y = game->player_coord.y;
	mlx_put_image_to_window(game->mlx, game->win, img, x * GRID_SIZE, y * GRID_SIZE);
	return(0);
}

bool exist_wall(char grid)
{
	if (grid == '1')
		return (true);
	return (false);
}

bool exist_exit(char grid, t_game *game)
{
	if (grid == 'E')
	{
		if (game->rem_dot == 0)
			close_window(game);
		return (true);
	}
	return (false);
}

bool exist_dot(char grid)
{
	if (grid == 'C')
		return (true);
	return (false);
}

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
		game->rem_dot -= 1;
	mlx_put_image_to_window(game->mlx, game->win, img, prev_x * GRID_SIZE, prev_y * GRID_SIZE);
	game->player_coord.x = next_x;
	game->player_coord.y = next_y;
	put_steps();
}

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

void set_events(t_game *game)
{
	mlx_key_hook(game->win, check_key_entry, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_do_key_autorepeaton(game->mlx);
}
