#include "so_long.h"

/* "./ber" is invalid file name. */
bool is_valid_file_name(char *file_name)
{
	if (ft_strlen(file_name) == 5 && ft_strncmp(file_name, "./ber", 5))	
		return (false);
	return (true);
}

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

bool is_valid_map(char **map)
{
	(void)map;
	return(true);
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
