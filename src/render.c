#include "so_long.h"

void	*get_tip_image(int pos_y, int pos_x, t_game *game)
{
	t_img img;

	img = game->img;	
	if (game->map[pos_y][pos_x] == '1')
		return(img.wall);
	else if (game->map[pos_y][pos_x] == 'C')
		return(img.dot);
	else if (game->map[pos_y][pos_x] == 'E')
		return(img.exit);
	return (NULL);
}

void	draw_map(t_game *game)
{
	int		i;
	int 	j;
	void	*img;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 31)
		{
			img = get_tip_image(i, j, game);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, 
					j * GRID_SIZE, i * GRID_SIZE);
			j++;
		}
		i++;
	}
}
