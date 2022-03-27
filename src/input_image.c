#include "so_long.h"

void *convert_file_into_image(void *mlx, char *img_file)
{
	int img_width;
	int img_height;
	void *image;

	image = mlx_xpm_file_to_image(mlx, img_file, &img_width, &img_height);
	if (image == NULL || img_height != GRID_SIZE || img_width != GRID_SIZE)
		put_error_and_exit(ERR_FILE_FMT);
	return (image);
}

void	load_images(t_game *game)
{
	game->img.floor = convert_file_into_image(game->mlx, IMG_FILE_FLOOR);
	game->img.wall = convert_file_into_image(game->mlx, IMG_FILE_WALL); 
	game->img.dot = convert_file_into_image(game->mlx, IMG_FILE_DOT);
	game->img.player = convert_file_into_image(game->mlx, IMG_FILE_PLAYER);
	game->img.exit = convert_file_into_image(game->mlx, IMG_FILE_EXIT);
}
