#include "so_long.h"
#include <time.h>

void put_image_to_window(t_game *game, void *img, t_vector2 pos)
{
	t_vector2 draw_pos;

	draw_pos = ft_vector_mul(pos, GRID_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, img, draw_pos.x, draw_pos.y);
}

void *xpm_file_to_image(void *mlx, char *img_file, int size)
{
	int img_width;
	int img_height;
	void *image;

	image = mlx_xpm_file_to_image(mlx, img_file, &img_width, &img_height);
	if (image == NULL || (size && img_height != size) || (size && img_width != size))
		put_error_and_exit(ERR_FILE_FMT);
	return (image);
}


void	char_lstiter(t_game *game, void(*func)(t_game *, t_clist *character))
{
	t_clist	*player;
	t_clist	*enemy;

	player = game->player;
	if (!player)
		return ;
	while (player)
	{
		func(game, player);
		player = player->next;
	}
	enemy = game->enemy;
	if (!enemy)
		return ;
	while (enemy)
	{
		func(game, enemy);
		enemy = enemy->next;
	}
}
