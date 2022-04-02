#include "so_long.h"

# define MENU_SIZE 16

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
	game->img.floor = convert_file_into_image(game->mlx, IMG_FILE_FLOOR, GRID_SIZE);
	game->img.wall = convert_file_into_image(game->mlx, IMG_FILE_WALL, GRID_SIZE); 
	game->img.dot = convert_file_into_image(game->mlx, IMG_FILE_DOT, GRID_SIZE);
	game->img.exit = convert_file_into_image(game->mlx, IMG_FILE_EXIT, GRID_SIZE);
}

void load_digit_images(t_game *game)
{
	game->img.digit[0] = convert_file_into_image(game->mlx, IMG_FILE_ZERO, GRID_SIZE);
	game->img.digit[1] = convert_file_into_image(game->mlx, IMG_FILE_ONE, GRID_SIZE);
	game->img.digit[2] = convert_file_into_image(game->mlx, IMG_FILE_TWO, GRID_SIZE);
	game->img.digit[3] = convert_file_into_image(game->mlx, IMG_FILE_THREE, GRID_SIZE);
	game->img.digit[4] = convert_file_into_image(game->mlx, IMG_FILE_FOUR, GRID_SIZE);
	game->img.digit[5] = convert_file_into_image(game->mlx, IMG_FILE_FIVE, GRID_SIZE);
	game->img.digit[6] = convert_file_into_image(game->mlx, IMG_FILE_SIX, GRID_SIZE);
	game->img.digit[7] = convert_file_into_image(game->mlx, IMG_FILE_SEVEN, GRID_SIZE);
	game->img.digit[8] = convert_file_into_image(game->mlx, IMG_FILE_EIGHT, GRID_SIZE);
	game->img.digit[9] = convert_file_into_image(game->mlx, IMG_FILE_NINE, GRID_SIZE);
}

void load_footer_images(t_game *game)
{
	game->img.menu = convert_file_into_image(game->mlx, IMG_FILE_MENU, 0);
	game->img.logo = convert_file_into_image(game->mlx, IMG_FILE_LOGO, 0);
	game->img.title = convert_file_into_image(game->mlx, IMG_FILE_TITLE, 0);
}

void load_character_images(t_game *game)
{
	game->img.player[STAT_DOWN] = convert_file_into_image(game->mlx, IMG_FILE_P_DOWN, GRID_SIZE);
	game->img.player[STAT_UP] = convert_file_into_image(game->mlx, IMG_FILE_P_UP, GRID_SIZE);
	game->img.player[STAT_LEFT] = convert_file_into_image(game->mlx, IMG_FILE_P_LEFT, GRID_SIZE);
	game->img.player[STAT_RIGHT] = convert_file_into_image(game->mlx, IMG_FILE_P_RIGHT, GRID_SIZE);
}

void load_images(t_game *game)
{
	load_character_images(game);
	load_object_images(game);
	load_digit_images(game);
	load_footer_images(game);
}


