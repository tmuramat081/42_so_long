#ifndef SO_LONG_H
# define SO_LONG_H

# include "game_config.h"
# include "system_message.h"
# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_img {
	void 	*floor;
	void 	*wall;
	void	*dot;
	void	*exit;
	void	*player[4];
	void	*digit[10];
	void	*menu;
	void	*logo;
	void	*title;
}	t_img;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef enum e_stat {
	STAT_DOWN,
	STAT_UP,
	STAT_LEFT,
	STAT_RIGHT,
	STAT_FINISHED,
	STAT_END
}	t_stat;

typedef struct s_chk {
	size_t	cnt_dot;
	size_t	cnt_exit;
	size_t	cnt_player;
	int		width_lim;
	int		height_lim;
}	t_chk;

typedef struct s_clist {
	t_coord coord;
	t_stat	stat;
	void	*next;
}	t_clist;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	size_t	map_width;
	size_t	map_height;
	t_coord	player_coord;
	t_stat	p_stat;
	t_img	img;
	size_t	cnt_dot;
	size_t	cnt_step;
}	t_game;

/*** main.c ***/
void	input_map(t_game *game, char *map_file);
void	init_game(t_game *game);

/*** input_map.c ***/
char **load_map_file(char *file, t_game *game);
void	parse_line_info(char *map_line, t_game *game);
void	pstdr_grid_info(char *map_line, size_t y, size_t x,  t_game *game);

/*** input_image.c ***/ 
void	load_images(t_game *game);
void 	*convert_file_into_image(void *mlx, char *img_file, int size);

/*** render.c ***/
void	*get_grid_image(int y, int x, t_game *game);
int		render_frame(t_game *game);
void	render_map(t_game *game);
int		render_player(t_game *game);
void	render_steps(size_t num, t_game *game);
void	render_footer(t_game *game);

/*** animation.c ***/
void	move_animation(t_coord *prev, t_coord *next);

/*** set_event.c ***/
void	set_events(t_game *game);
int		check_key_entry(int keycode, t_game *game);
void	move_player(t_game *game, t_coord next);
bool	exist_dot(char grid);
bool	exist_exit(char grid, t_game *game);
bool	exist_wall(char grid);

/*** validate_map.c ***/
void	check_is_playable_map(t_game *game, const char **src_map);
void 	expolore_map(char **map, int x, int y, t_chk *map_checker);
void	get_grid_info(char grid, t_chk *map_checker);
bool	is_valid_map(char **map);
bool	is_valid_file_name(char *file_name);

int		close_window(t_game *game);
/*** utils.c ***/
void	put_steps(t_game *game);
void	put_error_and_exit(char *err_msg);
void	put_end_message(t_game *game);
#endif