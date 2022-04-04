#include "so_long.h"

# define STEP_MAX 999
# define BLACK 0x00000000
# define TITLE_WIDTH 6

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
	t_vector2 put_pos;

	img = game->img.player[game->player->state];
	put_pos = ft_vector_scalar_mul(game->player->pos, GRID_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, img, put_pos.x, put_pos.y);
	return (0);
}

void	render_map(t_game *game)
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
}

void	render_steps(size_t num, t_game *game)
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
}

void	render_footer(t_game *game)
{
	size_t 	offset;
	t_img	img;
	size_t	i;

	img = game->img;
	offset = game->map_height * GRID_SIZE;

	mlx_put_image_to_window(game->mlx, game->win, img.logo, 0, offset);
	i = 1;
	while (i < game->map_width)
	{
		mlx_put_image_to_window(game->mlx, game->win, img.menu, i * GRID_SIZE, offset);
		if (i + TITLE_WIDTH == game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->win, img.title, i * GRID_SIZE, offset);
			break ;
		}
		i++;
	}
}

int render_frame(t_game *game)
{
	render_map(game);
	render_player(game);
	render_footer(game);
	return (0);
}