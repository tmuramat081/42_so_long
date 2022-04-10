#include "so_long.h"
#include "ft_snprintf.h"


void load_character_images(t_game *game, void **img, const char *directory)
{
	int i;
	char file_path[PATH_MAX];

	i = 0;
	while (i < N_FRAMES)
	{
		ft_snprintf(file_path, sizeof(file_path), "%s%d.xpm", directory, i);
		img[i] = xpm_file_to_image(game->mlx, file_path, GRID_SIZE);
		i++;
	}
}

void	load_animation(t_game *game)
{
	const char *player_img_directory[4] = {
		XPM_PLAYER_DOWN,
		XPM_PLAYER_UP,
		XPM_PLAYER_LEFT,
		XPM_PLAYER_RIGHT,
	};
	const char *enemy_img_directory[4] = {
		XPM_ENEMY_DOWN,
		XPM_ENEMY_UP,
		XPM_ENEMY_LEFT,
		XPM_ENEMY_RIGHT,
	};
	int i;
	
	i = 0;
	while (i < DIR_END)
	{
		load_character_images(game, game->img.player[i], player_img_directory[i]);
		load_character_images(game, game->img.enemy[i], enemy_img_directory[i]);
		i++;
	}
}