#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WINDOW_TITLE "So long"

typedef struct s_game{
	void *mlx;
	void *win;
} t_game;

#endif