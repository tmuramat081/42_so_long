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

void	load_object_images(t_game *game)
{
	game->img.floor = convert_file_into_image(game->mlx, IMG_FILE_FLOOR);
	game->img.wall = convert_file_into_image(game->mlx, IMG_FILE_WALL); 
	game->img.dot = convert_file_into_image(game->mlx, IMG_FILE_DOT);
	game->img.player = convert_file_into_image(game->mlx, IMG_FILE_PLAYER);
	game->img.exit = convert_file_into_image(game->mlx, IMG_FILE_EXIT);
}

void load_digit_images(t_game *game)
{
	game->img.digit[0] = convert_file_into_image(game->mlx, IMG_FILE_ZERO);
	game->img.digit[1] = convert_file_into_image(game->mlx, IMG_FILE_ONE);
	game->img.digit[2] = convert_file_into_image(game->mlx, IMG_FILE_TWO);
	game->img.digit[3] = convert_file_into_image(game->mlx, IMG_FILE_THREE);
	game->img.digit[4] = convert_file_into_image(game->mlx, IMG_FILE_FOUR);
	game->img.digit[5] = convert_file_into_image(game->mlx, IMG_FILE_FIVE);
	game->img.digit[6] = convert_file_into_image(game->mlx, IMG_FILE_SIX);
	game->img.digit[7] = convert_file_into_image(game->mlx, IMG_FILE_SEVEN);
	game->img.digit[8] = convert_file_into_image(game->mlx, IMG_FILE_EIGHT);
	game->img.digit[9] = convert_file_into_image(game->mlx, IMG_FILE_NINE);
}

void load_images(t_game *game)
{
	load_object_images(game);
	load_digit_images(game);
}


