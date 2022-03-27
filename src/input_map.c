#include "so_long.h"
#include "get_next_line.h"


void	check_grid_info(char **map, size_t y, size_t x,  t_game *game)
{

	if (map[y][x] == 'C')
		game->rem_dot += 1;
	if (map[y][x] == 'P')
	{
		if (game->player_coord.y && game->player_coord.x)
			put_error_and_exit(ERR_PLAYERS);
		game->player_coord.y = y;
		game->player_coord.x = x;
	}
	
}

void	parse_map(char **map, t_game *game)
{
	size_t i;
	size_t j;
	
	game->map_width = ft_strcspn(map[2], "\n\r");
	printf("%ld\n", game->map_width);
	i = 0;
	while (map[i])
	{
		if (game->map_width != ft_strcspn(map[i], "\n\r"))
			put_error_and_exit(ERR_MAP_FMT);
		j = 0;
		while (map[i][j])
		{
			check_grid_info(map, i, j, game);
			j++;
		}
		i++;
	}
	game->map_height = i;
}

char **load_map_file(char *file)
{
	int		fd;
	char	**map;
	size_t	i;

	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * MAP_SIZE_MAX + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (true)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	return (map);
}

void input_map(t_game *game, char *map_file)
{
	char **map;

	if (is_valid_file_name(map_file) == false)
		put_error_and_exit(ERR_FILE_NAME);
	map = load_map_file(map_file);
	parse_map(map, game);
	check_playable_map(game, (const char **)map);
	game->map = map;
}