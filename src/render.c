#include "so_long.h"

# define STEP_MAX 999
# define BLACK 0x00000000

void	*get_grid_image(int y, int x, t_game *game)
{
	void *img;

	if (game->map[y][x] == '1')
		img = game->img.wall;
	else if (game->map[y][x] == 'C')
		img = game->img.dot;
	else if (game->map[y][x] == 'E')
		img = game->img.exit;
	else
		img = game->img.floor;
	return (img);
}

int	render_player(t_game *game)
{
	void *img;
	int x;
	int y;

	img = game->img.player;
	x = game->player_coord.x;
	y = game->player_coord.y;
	mlx_put_image_to_window(game->mlx, game->win, img, x * GRID_SIZE, y * GRID_SIZE);
	return (0);
}

int	render_map(t_game *game)
{
	size_t	i;
	size_t 	j;
	void	*img;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			img = get_grid_image(i, j, game);
			mlx_put_image_to_window(game->mlx, game->win, img, j * GRID_SIZE, i * GRID_SIZE);
			j++;
		}
		i++;
	}
	return (0);
}

int	render_steps(size_t num, t_game *game)
{
	static int	i;
	void		*img;

	img = game->img.digit[num % 10];
	if (num / 10)
		render_steps(num / 10, game);
	else
		i = 1;
	mlx_put_image_to_window(game->mlx, game->win, img, i * GRID_SIZE, game->map_height * GRID_SIZE);
	i++;
	return (0);
}

int	render_footer(t_game *game)
{
	size_t 	offset;
	void	*logo;
	void	*menu;
	void	*title;
	size_t	i;

	logo = game->img.logo;
	menu = game->img.menu;
	title = game->img.title;
	offset = game->map_height * GRID_SIZE;

	mlx_put_image_to_window(game->mlx, game->win, logo, 0, offset);
	i = 1;
	while (i < game->map_width)
	{
		mlx_put_image_to_window(game->mlx, game->win, menu, i * GRID_SIZE, offset);
		if (i + 6 == game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->win, title, i * GRID_SIZE, offset);
			break ;
		}
		i++;
	}
	return (0);
}