#include "so_long.h"

int render_next_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.player, game->player_pos.x * GRID_SIZE, game->player_pos.y * GRID_SIZE);	
	return(0);
}

int hook_player_move(int keycode, t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.floor, game->player_pos.x * GRID_SIZE, game->player_pos.y * GRID_SIZE);	
	if (keycode == KEY_A || keycode == KEY_LEFT)
		game->player_pos.x -= 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->player_pos.x += 1; 
	else if (keycode == KEY_W || keycode == KEY_UP)
		game->player_pos.y -= 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->player_pos.y += 1;
	else if (keycode == KEY_ESC)
		mlx_destroy_window(game->mlx, game->win);
	printf("KEYCODE:%d\n", keycode);
	return (0);
}

void set_hook(t_game *game)
{
	mlx_key_hook(game->win, hook_player_move, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
}
