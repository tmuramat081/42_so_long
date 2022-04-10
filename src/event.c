#include "so_long.h"
#include "time.h"

const double	g_frame_time = 1.0 / FPS_MAX;

bool is_passable_grid(t_game *game, t_vector2 next_pos)
{
	char grid;

	grid = game->map[next_pos.y][next_pos.x];
	if (grid == '1')
		return (false);
	else if (grid == 'E')
	{
		if (game->cnt_dot == 0)
			close_window(game);
		return (false);
	}
	return (true);
}

bool	exist_collective(t_game *game, t_vector2 next)
{
	if (game->map[next.y][next.x] == 'C')
	{
		game->map[next.y][next.x] = '0';
		return (true);
	}
	return (false);
}

void	set_to_move_character(t_game *game, t_clist *character)
{
	t_vector2 next_pos;

	next_pos = ft_vector_add(character->pos, character->vector);
	if (is_passable_grid(game, next_pos) == false)
		character->vector = (t_vector2){};
	else if (exist_collective(game, next_pos) == true)
		game->cnt_dot -= 1;
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

int	update_game(t_game *game)
{
	clock_t start_time;

	start_time = clock();
	if(game->is_key_pressed == true)
	{
		char_lstiter(game, &set_to_move_character);
		char_lstiter(game, &check_hit);
	}
	char_lstiter(game, &render_animation);
	limit_frame_rate(start_time);
	game->is_key_pressed = false;
	return (0);
}

/* Hook functions in mlx loop. */
void set_events(t_game *game)
{
	mlx_hook(game->win, 02, 1L<<0, check_key_entry, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, update_game, game);
	mlx_expose_hook (game->win, render_frame, game);
	mlx_do_key_autorepeatoff(game->mlx);
}
