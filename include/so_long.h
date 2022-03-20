#ifndef SO_LONG_H
# define SO_LONG_H

# include "game_config.h"
# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_img{
	void *floor;
	void *wall;
	void *dot;
	void *exit;
	void *player;
} t_img;

typedef struct s_game{
	void	*mlx;
	void	*win;
	int		win_size_x;
	int		win_size_y;
	int		spawn_x;
	int		spawn_y;
} t_game;

#endif