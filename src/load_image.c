#include "so_long.h"
#include "ft_snprintf.h"

void *convert_file_into_image(void *mlx, char *img_file, int size)
{
	int img_width;
	int img_height;
	void *image;

	image = mlx_xpm_file_to_image(mlx, img_file, &img_width, &img_height);
	if (image == NULL || (size && img_height != size) || (size && img_width != size))
		put_error_and_exit(ERR_FILE_FMT);
	return (image);
}

void	load_object_images(t_game *game)
{
	game->img.floor = convert_file_into_image(game->mlx, XPM_FLOOR, GRID_SIZE);
	game->img.wall = convert_file_into_image(game->mlx, XPM_WALL, GRID_SIZE); 
	game->img.dot = convert_file_into_image(game->mlx, XPM_DOT, GRID_SIZE);
	game->img.exit = convert_file_into_image(game->mlx, XPM_EXIT, GRID_SIZE);
}

void load_footer_images(t_game *game)
{
	game->img.menu = convert_file_into_image(game->mlx, XPM_MENU, 0);
	game->img.logo = convert_file_into_image(game->mlx, XPM_LOGO, 0);
	game->img.title = convert_file_into_image(game->mlx, XPM_TITLE, 0);
}

void load_counter_images(t_game *game)
{
	char file_path[PATH_MAX];
	int i;

	i = 0;
	while (i < 10)
	{
		ft_snprintf(file_path, sizeof(file_path), "%s%d.xpm", XPM_DIGIT, i);
		game->img.digit[i] = convert_file_into_image(game->mlx, file_path, GRID_SIZE);
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


