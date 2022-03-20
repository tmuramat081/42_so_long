#include "so_long.h"
#include "get_next_line.h"

int hook_player_move(int key, t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("KEY_HOOK");
}

void set_game_event(t_game *game, char **map)
{
	mlx_hook(game->win, 3, 1L<<0, hook_player_move, game);

}

void project_map(t_game *game, char **map, t_img *img)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, img->floor, j * 32, i * 32);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, img->wall, j * 32, i * 32);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, img->dot, j * 32, i * 32);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, img->player, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game, char **map, t_img *img)
{
	int width;
	int height;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 600, 600, WINDOW_TITLE);
	img->floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &width, &height);
	img->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &width, &height);
	img->dot = mlx_xpm_file_to_image(game->mlx, "./img/dot.xpm", &width, &height);
	img->player = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &width, &height);
	project_map(game, map, img);
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
	t_game game;
	t_img img;
	char **map;

	if (argc != 2)
		exit(1);
	ft_bzero(&game, sizeof(t_game));
	map = input_file(&game, argv[1]);
	init_game(&game, map, &img);
	set_game_event(&game, map);
	mlx_loop(game.mlx);
	return (0);
}