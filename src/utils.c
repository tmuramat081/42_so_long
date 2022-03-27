#include "so_long.h"

void	put_steps(void)
{
	static int cnt_step;

	cnt_step += 1;
	ft_putstr_fd("\033[32m\033[1K\033[1G", 1);
	ft_putstr_fd("STEP:", 1);
	ft_putnbr_fd(cnt_step , 1);
	ft_putstr_fd("\033[49m", 1);
}

void	put_error_and_exit(char *err_msg)
{
	ft_putstr_fd("\033[31m", 1);
	ft_putendl_fd(err_msg, 1);
	ft_putstr_fd("\033[49m", 1);
	exit(EXIT_FAILURE);
}
