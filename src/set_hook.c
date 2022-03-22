#include "so_long.h"

int render_next_frame(t_game *game)
{
	draw_map(game);	
}

int hook_player_move(int keycode, t_game *game)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
		game->player_pos->x -= 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		game->player_pos->x += 1; 
	else if (keycode == KEY_W || keycode == KEY_UP)
		game->player_pos->y += 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		game->player_pos->y -= 1;
	else if (keycode == KEY_ESC)
		mlx_destroy_window(game->mlx, game->win);
	printf("KEYCODE:%d\n", keycode);
}

void set_hook(t_game *game)
{
	mlx_key_hook(game->win, hook_player_move, game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
}
