#include "so_long.h"

void	load_image_file(t_game *game)
{
	int width;
	int height;

	game->img->floor = mlx_xpm_file_to_image(game->mlx, IMG_FILE_FLOOR, &width, &height);
	game->img->wall = mlx_xpm_file_to_image(game->mlx, IMG_FILE_WALL, &width, &height);
	game->img->dot = mlx_xpm_file_to_image(game->mlx, IMG_FILE_DOT, &width, &height);
	game->img->player = mlx_xpm_file_to_image(game->mlx, IMG_FILE_PLAYER, &width, &height);
}