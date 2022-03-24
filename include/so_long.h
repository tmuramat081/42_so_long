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

typedef struct s_img {
	void *floor;
	void *wall;
	void *dot;
	void *exit;
	void *player;
}	t_img;

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

typedef struct s_mchk{
	int		cnt_dot; 
	int		cnt_exit;
	bool	is_invalid_c;
	bool 	is_map_opened;
	int		cnt_player;
	int		cnt_enemy;
}	t_mchk;

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_pos	player_pos;
	t_img	img;
	char	**map;
	size_t	step;
}	t_game;

void	input_map(t_game *game, char *map_file);
void	input_image(t_game *game);
void	init_game(t_game *game);
void	draw_map(t_game *game);
void	set_hook(t_game *game);
void	put_error_and_exit(char *err_msg);

#endif