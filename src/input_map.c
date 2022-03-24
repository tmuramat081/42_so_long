#include "so_long.h"

void get_map_info(char grid, t_mchk *map_checker)
{
	if (grid == '0')
		return ;
	else if (grid == 'E')
		map_checker->cnt_exit += 1;
	else if (grid == 'C')
		map_checker->cnt_dot += 1;
	else if (grid == 'P')
		map_checker->cnt_player += 1;
	else if (grid == 'E')
		map_checker->cnt_enemy += 1;
		
}

void full_search_map(char **map, int x, int y, t_mchk *map_checker)
{
	get_map_info(map[y][x], map_checker);
	if (map[y][x] != '1')
	{
		map[y][x] = '1';
		full_search_map(map, x+1, y, map_checker);
		full_search_map(map, x-1, y, map_checker);
		full_search_map(map, x, y+1, map_checker);
		full_search_map(map, x, y-1, map_checker);
	}
}

void load_map_file(t_game *game, char *file)
{
	int		fd;
	char	*map[MAP_SIZE_MAX];

	fd = open(file, O_RDONLY);
	while (true)
	{
		*map = get_next_line(fd);
		if (*map == NULL)
			break ;
		(*map)++;
	}
	game->map = map;
}

/* "./ber" is invalid file name. */
bool is_valid_file_name(char *file_name)
{
	if (ft_strlen(file_name) == 5 && ft_strncmp(file_name, "./ber", 5))	
		return (false);
	return (true);
}

bool is_valid_map(char **map)
{
	(void)map;
	return(true);
}


void parse_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
//			check_grid(game->map[i][j]);
			j++;
		}
		i++;
	}
}



void input_map(t_game *game, char *map_file)
{
	if (is_valid_file_name(map_file) == false)
		put_error_and_exit("ERROR");
	load_map_file(game, map_file);
	parse_map(game);
	if (is_valid_map(game->map) == false)
		put_error_and_exit("ERROR");
}