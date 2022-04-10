#include "so_long.h"
#include "ft_snprintf.h"


void	load_object_images(t_game *game)
{
	game->img.floor = xpm_file_to_image(game->mlx, XPM_FLOOR, GRID_SIZE);
	game->img.wall = xpm_file_to_image(game->mlx, XPM_WALL, GRID_SIZE); 
	game->img.dot = xpm_file_to_image(game->mlx, XPM_DOT, GRID_SIZE);
	game->img.exit = xpm_file_to_image(game->mlx, XPM_EXIT, GRID_SIZE);
}

void load_footer_images(t_game *game)
{
	game->img.menu = xpm_file_to_image(game->mlx, XPM_MENU, 0);
	game->img.logo = xpm_file_to_image(game->mlx, XPM_LOGO, 0);
	game->img.title = xpm_file_to_image(game->mlx, XPM_TITLE, 0);
}

void load_counter_images(t_game *game)
{
	char file_path[PATH_MAX];
	int i;

	i = 0;
	while (i < 10)
	{
		ft_snprintf(file_path, sizeof(file_path), "%s%d.xpm", XPM_DIGIT, i);
		game->img.digit[i] = xpm_file_to_image(game->mlx, file_path, GRID_SIZE);
		i++;
	}
}

void load_images(t_game *game)
{
	load_object_images(game);
	load_footer_images(game);
	load_counter_images(game);
	load_animation(game);
}


