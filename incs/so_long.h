/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:27:15 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/13 01:27:15 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	size_t	cnt_collect;
	size_t	cnt_exit;
	size_t	cnt_player;
	bool	is_obj_error;
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
	TYPE_NONE
}	t_type;

typedef struct s_clist {
	t_type		type;
	t_vector2	pos;
	t_vector2	vector;
	t_timespec	anim_time;
	t_vector2	anim_pos;
	t_dir		dir;
	short		frame;
	void		*next;
}	t_clist;

typedef struct s_img {
	void	*back;
	void	*wall;
	void	*collect;
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
	t_clist	*character;
	t_img	img;
	size_t	cnt_collect;
	size_t	cnt_step;
	short	frame;
	bool	is_key_pressed;
}	t_game;

/*** main.c ***/
void	input_map(t_game *game, char *map_file);
void	init_game(t_game *game);

/*** map_input.c ***/
char	**load_map_file(char *file, t_game *game);
void	parse_line_size(char *map_line, t_game *game);
void	parse_grid_object(char *map_line, size_t y, t_game *game);
bool	is_valid_file_name(char *file_name);

/*** map_check.c ***/
void	validate_map_playability(t_game *game);
bool	compare_explored_map(t_game *game, t_chk map_checker);
void	explore_map(char **map, t_vector2 pos, t_chk *map_checker);
void	check_grid_object(char grid, t_chk *map_checker);

/*** load_image.c ***/
void	load_images(t_game *game);
void	load_object_images(t_game *game);
void	load_character_sprites(t_game *game, void **img, const char *directory);
void	load_footer_images(t_game *game);
void	load_counter_images(t_game *game);

/*** load_animation.c ***/
void	load_animation(t_game *game);
void	load_character_frames(t_game *game, void **img, const char *directory);

/*** render_image.c ***/
int		render_frame(t_game *game);
void	*get_object_image(int y, int x, t_game *game);
void	render_map(t_game *game);
void	render_footer(t_game *game);
void	render_steps(size_t num, t_game *game);

/*** render_animation.c ***/
void	render_animation(t_game *game, t_clist *character);
void	render_standing_animation(t_game *game, t_clist *character);
void	render_moving_animation(t_game *game, t_clist *character);
void	draw_lerp_position(t_game *game, t_clist *character, float time);
void	*get_animation_image(t_game *game, t_clist *character);

/*** game.c ***/
void	set_game_hooks(t_game *game);
int		update_game(t_game *game);
void	limit_frame_rate(t_timespec *start_time);

/*** game_key.c ***/
int		check_key_entry(int keycode, t_game *game);
void	set_player_dir(t_clist *character, t_dir dir);

/*** game_move.c ***/
void	detect_object_collision(t_game *game, t_clist *character);
bool	collective_exists(t_game *game, t_vector2 next);
bool	exit_exists(t_game *game, t_vector2 next);
bool	wall_exists(t_game *game, t_vector2 next);

/*** game_  ***/
void	detect_character_collision(t_game *game, t_clist	*character);
t_clist	*target_exists(t_vector2 pos, t_vector2 next_pos, t_clist *target);

/*** game_enemy.c ***/
void	set_enemy_move(t_game *game, t_clist *character);
void	random_horizontal_move(t_clist *enemy);

/*** game_end.c ***/
int		close_window(t_game *game, char *message);
void	check_game_state(t_game *game, t_clist *character);

/*** utils_print.c ***/
void	put_error_and_exit(char *err_msg);
void	put_steps(t_game *game);
void	put_end_message(char *message);

/*** utils_list.c ***/
void	character_lstnew(t_clist **lst, t_vector2 pos, t_type type);
void	character_lstadd_back(t_clist **lst, t_clist *new_character);
void	character_lstclear(t_clist **character);

/*** utils_wrapper.c ***/
void	char_lstiter(t_game *game, void (*func)(t_game *, t_clist *));
void	*xpm_file_to_image(void *mlx, char *img_file, int size);
void	put_image_to_window(t_game *game, void *img, t_vector2 pos);

#endif