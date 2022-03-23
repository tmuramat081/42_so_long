#include "so_long.h"

void get_grid_info(char grid, t_mchk *map_checker)
{
	if (grid == 'E')
		map_checker->is_no_exit = false;
	else if (grid == 'C')
		map_checker->cnt_dot += 1;
	else if (grid == '\0')
		put_error_and_exit("Error: map is not closed.");
	else if (grid == 'P')
		put_error_and_exit("Error: two or more players.");
}

void full_search_map(char **map, int x, int y, t_mchk *map_checker)
{
	get_grid_info(map[y][x], map_checker);
	if (map[y][x] != '1')
	{
		map[y][x] = '1';
		full_search_map(map, x+1, y, map_checker);
		full_search_map(map, x-1, y, map_checker);
		full_search_map(map, x, y+1, map_checker);
		full_search_map(map, x, y-1, map_checker);
	}
}

char **load_map_file(char *file)
{
	int		fd;
	char	**map[2];
	int 	i;
	t_mchk map_checker;

	map[0] = malloc(sizeof(char *) * MAP_SIZE_MAX);
	map[1] = malloc(sizeof(char *) * MAP_SIZE_MAX);
	fd = open(file, O_RDONLY);
	i = 1;
	while (i < MAP_SIZE_MAX)
	{
		map[0][i] = get_next_line(fd);
		if (!map[0][i])
			break ;
		map[1][i] = ft_strdup(map[0][i]);
		printf("%s", map[0][i]);
		i++;
	}
	close(fd);
	full_search_map(map[1], 3, 3, &map_checker);	
	return (map[0]);
}
