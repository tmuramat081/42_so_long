#include "so_long.h"
#include "get_next_line.h"

int hook_player_move(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		game->player_pos->x -= 1;
		printf("left\n");
	}
	else if (keycode == KEY_D)
		game->player_pos->x += 1; 
	else if (keycode == KEY_W)
		game->player_pos->y += 1;
	else if (keycode == KEY_S)
		game->player_pos->y -= 1;
	else if (keycode == KEY_ESC)
		mlx_destroy_window(game->mlx, game->win);
}

int	refresh_game(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img->floor, j * TIP_SIZE, i * TIP_SIZE);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img->wall, j * TIP_SIZE, i * TIP_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img->dot, j * TIP_SIZE, i * TIP_SIZE);
			else if (game->map[i][j] == 'E')
			{
				game->player_pos->y = i;
				game->player_pos->x = j;
				mlx_put_image_to_window(game->mlx, game->win, game->img->player, j * TIP_SIZE, i * TIP_SIZE);
			}
			j++;
		}
		i++;
	}	
}

void set_game_event(t_game *game)
{
	mlx_key_hook(game->win, hook_player_move, game);
	mlx_loop_hook(game->mlx, refresh_game, game);
}

void project_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img->floor, j * TIP_SIZE, i * TIP_SIZE);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img->wall, j * TIP_SIZE, i * TIP_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img->dot, j * TIP_SIZE, i * TIP_SIZE);
			else if (game->map[i][j] == 'E')
			{
				game->player_pos->y = i;
				game->player_pos->x = j; 
				mlx_put_image_to_window(game->mlx, game->win, game->img->player, j * TIP_SIZE, i * TIP_SIZE);
			}
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game)
{
	int width;
	int height;
	void *mlx = game->mlx;
	t_img *img = game->img;

	mlx = mlx_init();
	game->win = mlx_new_window(mlx, 600, 600, WINDOW_TITLE);
	img->floor = mlx_xpm_file_to_image(mlx, "./img/floor.xpm", &width, &height);
	img->wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &width, &height);
	img->dot = mlx_xpm_file_to_image(mlx, "./img/dot.xpm", &width, &height);
	img->player = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &width, &height);
	project_map(game);
}

char **input_file(t_game *game, char *file)
{
	int		fd;
	char	**map;
	int 	i;

	(void)game;
	map = malloc(sizeof(char *) * 20);
	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		printf("%s", map[i]);
		if (!map[i])
			break ;
		i++;
	}
	close(fd);
	return (map);
}

int	main (int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
		exit(1);
	game = calloc(1, sizeof(t_game));
	game->map = input_file(game, argv[1]);
	init_game(game);
	set_game_event(game);
	mlx_loop(game->mlx);
	return (0);
}