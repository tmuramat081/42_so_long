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
}	t_img;

typedef struct s_pos{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_pos	*player_pos;
	t_img	*img;
	char	**map;
}	t_game;

#endif