#include "so_long.h"
#include "get_next_line.h"

/* Count the number of dot, and locate player spawn point. */
void	parse_grid_info(char *map_line, size_t y, t_game *game)
{
	size_t x;

	x = 0;
	while (map_line[x])
	{
		if (map_line[x] == 'C')
			game->rem_dot += 1;
		else if (map_line[x] == 'P')
		{
			if (game->player_coord.y && game->player_coord.x)
				put_error_and_exit(ERR_PLAYERS);
			game->player_coord.y = y;
			game->player_coord.x = x;
		}
		x++;
	}
}

/* Check if the map is rectangular or square. */ 
void	parse_line_info(char *map_line, t_game *game)
{
	if (!game->map_width)
		game->map_width = ft_strcspn(map_line, "\n\r");
	else if (game->map_width > MAP_WIDTH_MAX)
		put_error_and_exit(ERR_MAP_LARGE);
	else if (game->map_width != ft_strcspn(map_line, "\n\r"))
		put_error_and_exit(ERR_MAP_FMT);
	game->map_height += 1;
}

/* Read a map file line by line, using get_next_line(subject of school 42). */
char **load_map_file(char *file, t_game *game)
{
	int		fd;
	char	**map;
	size_t	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * MAP_HEIGHT_MAX + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (i <= MAP_HEIGHT_MAX + 1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (map) ;
		parse_line_info(map[i], game);
		parse_grid_info(map[i], i, game);
		i++;
	}
	return (NULL);
}
