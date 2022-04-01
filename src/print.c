#include "so_long.h"
#include "ft_printf.h"

# define STEP_MAX 999

void	put_end_message(t_game *game)
{
	if (game->rem_dot == 0)
		ft_printf(WIN_GAME);
	else
		ft_printf(EXIT_GAME);
}


int	ft_count_digits(int num, int radix)
{
	int cnt;

	cnt = 0;
	while (num)
	{
		num /= radix;
		cnt += 1;
	}
	return (cnt);
}

void	put_steps(t_game *game)
{
	if (game->cnt_step > STEP_MAX)
		game->cnt_step = STEP_MAX;
	ft_printf("\033[1K\033[1G");
	ft_printf("STEP:%d", game->cnt_step);
	game->cnt_step += 1;
}

/*
void render_steps(t_game *mage)
{
	int	dig_max;
	int	dig_num;

	dig_max = ft_count_digits(STEP_MAX, 10);
	dig_num = dig_max;
	while (dig_num--)
		mlx_put_image_to_window(game->mlx, game->win, game->img.digit[cnt_step / dig_num], (dig_max - dig_num) * GRID_SIZE, 1 * GRID_SIZE);

}
*/

void	put_error_and_exit(char *err_msg)
{
	ft_printf("Error\n%s\n", err_msg);
	exit(EXIT_FAILURE);
}
