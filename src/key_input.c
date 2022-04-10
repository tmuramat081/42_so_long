#include "so_long.h"

/* Check what's ahead of the player, then rewrite own coordinates. */
void	set_player_dir(t_clist *player, t_dir dir)
{
	while (player)
	{
		player->dir = dir;
		if (dir == DIR_DOWN)
			player->vector = (t_vector2){0, 1};
		else if (dir == DIR_UP)
			player->vector = (t_vector2){0, -1};
		else if (dir == DIR_LEFT)
			player->vector = (t_vector2){-1, 0};
		else if (dir == DIR_RIGHT)
			player->vector = (t_vector2){1, 0};
		player = player->next;
	}
}

/* Set to call functions when keyboard is pressed. */
int check_key_entry(int keycode, t_game *game)
{
	if (game->is_key_pressed == true)
		return (0);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		set_player_dir(game->player, DIR_LEFT);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		set_player_dir(game->player, DIR_RIGHT);
	else if (keycode == KEY_W || keycode == KEY_UP)
		set_player_dir(game->player, DIR_UP);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		set_player_dir(game->player, DIR_DOWN);
	game->is_key_pressed = true;
	return (0);
}
