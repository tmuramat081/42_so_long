#include "so_long.h"
#include "time.h"

const double	g_frame_time = 1.0 / FPS_MAX;

bool is_legal_move(t_game *game, t_vector2 next)
{
	char *grid;

	grid = &game->map[next.y][next.x];
	if (*grid == '1')
		return (false);
	else if (*grid == 'E')
	{
		if (game->cnt_dot == 0)
			close_window(game);
		return (false);
	}
	else if (*grid == 'C')
	{
		*grid = '0';
		game->cnt_dot -= 1;
	}
	return (true);
}

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

/* Limit max FPS(Frame Per Second), using usleep function. */
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

void	update_action(t_game *game, t_clist *player)
{
	t_vector2 next;

	while (player)
	{
		next = ft_vector_add(player->pos, player->vector);
		if (is_legal_move(game, next) == false)	
			player->vector = (t_vector2){};
		player = player->next ;
	}
}

void	check_hit(t_game *game, t_clist	*character)
{
	t_vector2	my_pos;
	t_vector2	my_next;

	while (character)
	{
		my_pos = character->pos;
		my_next = ft_vector_add(my_pos, character->vector);
		if (is_hit_character(my_pos, my_next, game->player) == true)
			character->vector = (t_vector2){};
		character = character->next;
	}
}

int	update_game(t_game *game)
{
	clock_t start_time;

	start_time = clock();
	if(game->is_key_pressed == true)
	{
		update_action(game, game->player);
		check_hit(game, game->player);
//		check_hit(game, game->enemy);
		
	}
	render_animation(game, game->player);
	render_animation(game, game->enemy);
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
