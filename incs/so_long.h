#ifndef SO_LONG_H
# define SO_LONG_H

# include "game_config.h"
# include "game_message.h"
# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_chk {
	size_t	cnt_dot;
	size_t	cnt_exit;
	size_t	cnt_player;
	int		width_lim;
	int		height_lim;
}	t_chk;

typedef enum e_dir {
	DIR_DOWN,
	DIR_UP,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_END
}	t_dir;

typedef enum e_type {
	TYPE_PLAYER,
	TYPE_ENEMY,
}	t_type;


typedef struct s_clist {
	t_type		type;
	t_vector2 	pos;
	t_vector2	vector;
	t_timespec	anim_time;
	t_vector2	anim_pos;
	t_dir		dir;
	int			slide;
	void	*next;
}	t_clist;

typedef struct s_img {
	void 	*floor;
	void 	*wall;
	void	*dot;
	void	*exit;
	void	*player[DIR_END][N_FRAMES];
	void	*enemy[DIR_END][N_FRAMES];
	void	*digit[10];
	void	*menu;
	void	*logo;
	void	*title;
}	t_img;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	size_t	map_width;
	size_t	map_height;
	t_clist	*player;
	t_clist	*enemy;
	t_img	img;
	size_t	cnt_dot;
	size_t	cnt_step;
	bool	is_key_pressed;
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
void 	*xpm_file_to_image(void *mlx, char *XPM, int size);

void load_player_images(t_game *game);
void load_enemy_images(t_game *game);
void	load_animation(t_game *game);
/*** render.c ***/
void	*get_grid_image(int y, int x, t_game *game);
int		render_frame(t_game *game);
void	render_map(t_game *game);
int		render_player(t_game *game);
void	render_steps(size_t num, t_game *game);
void	render_footer(t_game *game);

/*** animation.c ***/
void	render_animation(t_game *game, t_clist *character);
void	render_moving_animation(t_game *game, t_clist *character);
void	render_standing_animation(t_game *game, t_clist *character);

/*** set_event.c ***/
void	set_events(t_game *game);
int		check_key_entry(int keycode, t_game *game);
void	set_key_input(t_game *game, t_vector2 vector, t_dir stat);
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


void character_lstnew(t_clist **lst, t_vector2 pos, t_type type);
void	put_image_to_window(t_game *game, void *img, t_vector2 pos);
bool	is_hit_character(t_vector2 pos, t_vector2 next, t_clist *character);
void	char_lstiter(t_game *game, void(*func)(t_game *, t_clist *character));
void	check_hit(t_game *game, t_clist *character);
void	limit_frame_rate(clock_t start_time);

#endif