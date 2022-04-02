#include "so_long.h"
#include "ft_printf.h"

# define STEP_MAX 999
# define GREEN "\033[32m"
# define DEFAULT "\033[m"

void	put_end_message(t_game *game)
{
	if (game->cnt_dot == 0)
		ft_printf(WIN_GAME);
	else
		ft_printf(EXIT_GAME);
}

void	put_steps(t_game *game)
{
	if (game->cnt_step > STEP_MAX)
		game->cnt_step = STEP_MAX;
	ft_printf("\033[1K\033[1G");
	ft_printf(GREEN);
	ft_printf("STEP:%d", game->cnt_step);
	ft_printf(DEFAULT);
	render_steps(game->cnt_step, game);
	game->cnt_step += 1;
}

void	put_error_and_exit(char *err_msg)
{
	ft_printf("Error\n%s\n", err_msg);
	exit(EXIT_FAILURE);
}
