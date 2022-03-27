#include "so_long.h"
#include "ft_printf.h"

void	put_end_message(t_game *game)
{
	if (game->rem_dot == 0)
		ft_printf(WIN_GAME);
	else
		ft_printf(EXIT_GAME);
}

void	put_steps(void)
{
	static int cnt_step;

	ft_printf("\033[1K\033[1G");
	ft_printf("STEP:%d", cnt_step);
	cnt_step += 1;
}

void	put_error_and_exit(char *err_msg)
{
	ft_printf("\033[31m");
	ft_printf(err_msg);
	ft_printf("\033[49m");
	exit(EXIT_FAILURE);
}
