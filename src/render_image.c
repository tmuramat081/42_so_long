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

void	render_map(t_game *game)
{
	size_t	x;
	size_t 	y;
	void	*img;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			img = get_grid_image(y, x, game);
			put_image_to_window(game, img, (t_vector2){x, y});
			x++;
		}
		y++;
	}
}

void	render_steps(size_t num, t_game *game)
{
	size_t y_offset;
	static int	x;
	void		*img;

	y_offset = game->map_height;
	img = game->img.digit[num % 10];
	if (num / 10)
		render_steps(num / 10, game);
	x = 1;
	put_image_to_window(game, img, (t_vector2){x, y_offset});
	x++;
}

void	render_footer(t_game *game)
{
	size_t 	y_offset;
	t_img	img;
	size_t	x;

	img = game->img;
	y_offset = game->map_height;

	put_image_to_window(game, img.logo, (t_vector2){0, y_offset});
	x = 1;
	while (x < game->map_width)
	{
		put_image_to_window(game, img.menu, (t_vector2){x, y_offset});
		if (x + TITLE_WIDTH == game->map_width)
		{
			put_image_to_window(game, img.title, (t_vector2){x, y_offset});
			break ;
		}
		x++;
	}
}

int render_frame(t_game *game)
{
	render_map(game);
	render_footer(game);
	render_steps(0, game);
	render_animation(game, game->player);
//	render_standing_animation(game, game->enemy);
	return (0);
}