#ifndef SO_LONG_H
# define SO_LONG_H

# include "game_config.h"
# include "system_message.h"
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

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_chk {
	size_t	cnt_dot;
	size_t	cnt_exit;
	size_t	cnt_player;
}	t_chk;

typedef struct s_game {
	void	*mlx;
	void	*win;
	size_t	map_width;
	size_t	map_height;
	t_coord	player_coord;
	t_img	img;
	char	**map;
	int		rem_dot;
	size_t	step;
}	t_game;

void	input_map(t_game *game, char *map_file);
void	load_images(t_game *game);
void	init_game(t_game *game);
void	render_map(t_game *game);
void	render_character(t_game *game);
void	set_events(t_game *game);
void	put_error_and_exit(char *err_msg);
void	put_steps(void);
bool	is_valid_map(char **map);
bool	is_valid_file_name(char *file_name);
void	check_playable_map(t_game *game, const char **map);
int		close_window(t_game *game);
void	end_game(t_game *game);
/*** utils.c ***/
void	put_steps(void);
#endif