#include "so_long.h"

void	*get_tip_image(char pos, t_game *game)
{
	t_img *img;

	img = game->img;	
	if (pos == '0')
		return(img->floor);
	else if (pos == '1')
		return(img->wall);
	else if (pos == 'C')
		return(img->dot);
	else if (pos == 'E')
		return (img->player);
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
			img = get_tip_image(game->map[i][j], game);
			mlx_put_image_to_window(game->mlx, game->win, img, 
				j * TIP_SIZE, i * TIP_SIZE);
			j++;
		}
		i++;
	}
}
