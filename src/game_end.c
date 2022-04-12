#include "so_long.h"

int 	close_window(t_game *game)
{
	put_steps(game);
	put_end_message(game);
	ft_free_matrix(&game->map);
	character_lstclear(&game->character);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	exit(0);
}

void	check_game_state(t_game *game, t_clist *character)
{
	bool is_any_moving;
	bool is_any_playing;
	
	is_any_moving = false;
	is_any_playing = false;
	while (character)
	{	
		if (character->type == TYPE_PLAYER)
		{
			if (character->vector.x || character->vector.y)
				is_any_moving = true;
			is_any_playing = true;
		}
		character = character->next;
	}
	if (is_any_moving == false)
		game->is_key_pressed = false;
	if (is_any_playing == false)
		close_window(game);	
}
