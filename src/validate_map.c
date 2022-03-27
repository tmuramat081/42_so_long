#include "so_long.h"

/* "./ber" is invalid file name. */
bool is_valid_file_name(char *file_name)
{
	if (ft_strlen(file_name) == 5 && ft_strncmp(file_name, ".ber", 5) == 0)	
		return (false);
	return (true);
}

void get_grid_info(char grid, t_chk *map_checker)
{
	if (grid == '0')
		return ;
	else if (grid == 'C')
		map_checker->cnt_dot += 1;
	else if (grid == 'E')
		map_checker->cnt_exit += 1;
	else if (grid == 'P')
		map_checker->cnt_player += 1;
	else if (grid == '\0')
		put_error_and_exit(ERR_NO_WALL);
	else
		put_error_and_exit(ERR_NO_READ);
}

void full_search_map(char **map, int x, int y, t_chk *map_checker)
{
	if (map[y][x] != '@' && map[y][x] != '1')
	{
		get_grid_info(map[y][x], map_checker);
		map[y][x] = '@';
		full_search_map(map, x+1, y, map_checker);
		full_search_map(map, x-1, y, map_checker);
		full_search_map(map, x, y+1, map_checker);
		full_search_map(map, x, y-1, map_checker);
	}
}

void	check_playable_map(t_game *game, const char **src_map)
{
	size_t	init_x;
	size_t	init_y;
	t_chk	map_checker;
	char **cpy_map;

	cpy_map = ft_matrixdup(src_map);
	map_checker = (t_chk){};
	init_x = game->player_coord.x;
	init_y = game->player_coord.y;
	full_search_map(cpy_map, init_x, init_y, &map_checker);
	ft_free_matrix(&cpy_map);
}
