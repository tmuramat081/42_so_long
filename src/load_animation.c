#include "so_long.h"
#include "ft_snprintf.h"

void load_player_images(t_game *game)
{
	const char *player_image[4] = {
		XPM_P_DOWN,
		XPM_P_UP,
		XPM_P_LEFT,
		XPM_P_RIGHT,
	};
	char file_path[PATH_MAX];
	int i;
	int j;

	i = DIR_DOWN;
	while (i <= DIR_RIGHT)
	{
		j = 0;
		while (j < 4)
		{
			ft_snprintf(file_path, sizeof(file_path), "%s%d.xpm", player_image[i], j);
			game->img.player[i][j] = convert_file_into_image(game->mlx, file_path, GRID_SIZE);
			j++;
		}
		i++;
	}
}

void	load_enemy_images(t_game *game)
{
	const char *enemy_image[4] = {
		XPM_E_DOWN,
		XPM_E_UP,
		XPM_E_LEFT,
		XPM_E_RIGHT,
	};
	char file_path[PATH_MAX];
	int i;
	int j;

	i = DIR_DOWN;
	while (i <= DIR_RIGHT)
	{
		j = 0;
		while (j < 4)
		{
			ft_snprintf(file_path, sizeof(file_path), "%s%d.xpm", enemy_image[i], j);
			game->img.enemy[i][j] = convert_file_into_image(game->mlx, file_path, GRID_SIZE);
			j++;
		}
		i++;
	}
}
