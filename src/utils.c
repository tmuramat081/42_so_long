#include "so_long.h"

void	put_error_and_exit(char *err_msg)
{
	ft_putendl_fd(err_msg, 1);
	exit(EXIT_FAILURE);
}