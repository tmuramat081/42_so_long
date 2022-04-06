#include "so_long.h"
#include "ft_snprintf.h"


void load_character_images(t_game *game, void **img, const char *directory)
{
	int i;
	char file_path[PATH_MAX];

	i = 0;
	while (i < 4)
	{
		ft_snprintf(file_path, sizeof(file_path), "%s%d.xpm", directory, i);
		img[i] = convert_file_into_image(game->mlx, file_path, GRID_SIZE);
		i++;
	}
}

void	load_animation(t_game *game)
{
	int i;
	const char *player_img_directory[4] = {
		XPM_P_DOWN,
		XPM_P_UP,
		XPM_P_LEFT,
		XPM_P_RIGHT,
	};
	const char *enemy_img_directory[4] = {
		XPM_E_DOWN,
		XPM_E_UP,
		XPM_E_LEFT,
		XPM_E_RIGHT,
	};

	i = DIR_DOWN;
	while (i <= DIR_RIGHT)
	{
		load_character_images(game, game->img.player[i], player_img_directory[i]);
		load_character_images(game, game->img.enemy[i], enemy_img_directory[i]);
		i++;
	}
}