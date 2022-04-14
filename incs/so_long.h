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
	bool	exists_collect;
	bool	exists_exit;
	bool	is_obj_unknown;
	bool	is_map_opened;
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
	TYPE_NONE = 0,
	TYPE_PLAYER = 1 << 0,
	TYPE_ENEMY = 1 << 1,
	TYPE_ALL = ~0
}	t_typ;

typedef struct s_clist {
	t_typ		type;
	t_vector2	pos;
	t_vector2	vector;
	t_timespec	anim_start;
	t_vector2	anim_pos;
	t_dir		dir;
	void		*next;
}	t_clist;

typedef struct s_img {
	void	*back;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player[DIR_END][NUM_FRAMES];
	void	*enemy[DIR_END][NUM_FRAMES];
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
	bool	is_key_locked;
}	t_game;

/*** main.c ***/
void	input_map(t_game *game, char *map_file);
void	init_game(t_game *game);

/*** map_input.c ***/
void	load_map_file(char *file, t_game *game);
void	parse_line_size(char *map_line, t_game *game);
void	parse_grid_object(char *map_line, size_t y, t_game *game);
bool	is_valid_file_name(char *file_name);

/*** map_check.c ***/
void	validate_map_playability(t_game *game, t_clist *character);
void	check_is_playabele_map(t_game *game, t_chk map_checker);
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
void	render_moving_animation(t_game *game, t_clist *character, void *img);
t_vector2	calculate_lerp_position(t_clist *character, float time);
void	update_cutternt_position(t_game *game, t_clist *character);
void	*get_animation_image(t_game *game, t_clist *character);

/*** game.c ***/
void	set_game_hooks(t_game *game);
int		update_game(t_game *game);
void	limit_frame_rate(t_timespec *start_time);

/*** game_player.c ***/
int		check_key_entry(int keycode, t_game *game);
void	set_player_dir(t_clist *character, t_dir dir);

/*** game_object.c ***/
void	manage_object_event(t_game *game, t_clist *character);
bool	collective_exists(t_game *game, t_vector2 next);
bool	exit_exists(t_game *game, t_vector2 next);
bool	wall_exists(t_game *game, t_vector2 next);

/*** game_collision  ***/
void	detect_character_collision(t_game *game, t_clist *character);
t_clist	*target_exists(t_vector2 pos, t_vector2 next_pos, t_clist *target);

/*** game_enemy.c ***/
void	set_enemy_dir(t_game *game, t_clist *character);
void	turn_around(t_clist *character);
void	go_straight(t_clist *character);
void	eat_glass(t_clist *character);

/*** game_end.c ***/
int		exit_game_normally(t_game *game);
void	free_game_buffer(t_game *game);
void	free_images(t_game *game);
void	free_counter_images(t_game *game, t_img img);
void	free_animation_images(t_game *game, t_img img);

/*** game_state.c ***/
void	check_game_state(t_game *game);
void	should_lock_key(t_game *game, t_clist *character);

/*** utils_print.c ***/
void	handle_process_error(t_game *game, char *err_msg);
void	put_steps(t_game *game);
void	put_end_message(char *message);
void	put_error_message(char *message);

/*** utils_list.c ***/
void	character_lstnew(t_game *game, t_vector2 pos, t_typ type);
void	character_lstadd_back(t_clist **lst, t_clist *new_character);
void	character_lstclear(t_clist **character);
size_t	char_lstiter(t_game *game, void (*f)(t_game *, t_clist *), t_typ type);

/*** utils_wrapper.c ***/
void	*xpm_file_to_image(t_game *game, char *img_file, int size);
void	put_image_to_window(t_game *game, void *img, t_vector2 pos);
void	destroy_image(void *mlx, void *img);

#endif