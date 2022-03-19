#include "so_long.h"
#include "get_next_line.h"

void	init_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 600, 600, WINDOW_TITLE);

}

void input_file(t_game *game, char *file)
{
	int		fd;
	char	*map;
	int 	i;

	(void)game;
	fd = open(file, O_RDONLY);
	printf("%d\n", fd);
	map = get_next_line(fd);
	i = 0;
	while (map)
	{
		map = get_next_line(fd);
		printf("%s\n", map);
		i++;
	}
	close(fd);
}

int	main (int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		exit(1);
	input_file(&game, argv[1]);
//	init_game(game);
//	mlx_loop(game.mlx);
	return (0);
}