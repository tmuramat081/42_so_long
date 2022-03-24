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

bool wall_exists(char **map, int next_x, int next_y)
{
	if (map[next_y][next_x] == '1')
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
	if (wall_exists(game->map, next_x, next_y) == true)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, img, prev_x * GRID_SIZE, prev_y * GRID_SIZE);
	game->player_coord.x = next_x;
	game->player_coord.y = next_y;
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
	else if (keycode == KEY_ESC)
		mlx_destroy_window(game->mlx, game->win);
	printf("KEYCODE:%d\n", keycode);
	return (0);
}

void set_hook(t_game *game)
{
	mlx_key_hook(game->win, check_key_entry, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
}
