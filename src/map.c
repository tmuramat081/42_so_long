#include "so_long.h"
#include "get_next_line.h"

/* Count the number of dot, and locate player spawn point. */
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

/* Check if the map is rectangular or square. */ 
void	parse_map(char **map, t_game *game)
{
	size_t i;
	size_t j;
	
	game->map_width = ft_strcspn(map[0], "\n\r");
	if (game->map_width > MAP_WIDTH_MAX)
		put_error_and_exit(ERR_MAP_LARGE);
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

bool	is_last_line(char *line, int row_num)
{
	if (line == NULL)
	{
		if (row_num == 0)
			put_error_and_exit(ERR_MAP_EMPTY);
		else
			return (true);
	}
	return (false);
}

/* Read a map file line by line, using get_next_line(subject of school 42). */
char **load_map_file(char *file)
{
	int		fd;
	char	**map;
	size_t	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		put_error_and_exit(ERR_NO_READ);
	map = malloc(sizeof(char *) * MAP_HEIGHT_MAX + 1);
	if (!map)
		put_error_and_exit(ERR_FILE_READ);
	i = 0;
	while (true)
	{
		if (MAP_HEIGHT_MAX < i)
			put_error_and_exit(ERR_MAP_LARGE);
		map[i] = get_next_line(fd);
		if (is_last_line(map[i], i) == true)
			break ;
		i++;
	}
	return (map);
}
