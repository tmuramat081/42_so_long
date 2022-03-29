#include "so_long.h"

/* "./ber" is invalid file name. */
bool is_valid_file_name(char *file_name)
{
	size_t len;

	len = ft_strlen(file_name);
	if (file_name[len - 5] != '/' && ft_strncmp(&file_name[len - 4], ".ber", 4) == 0)
		return (true);
	return (false);
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

void explore_map(char **map, int x, int y, t_chk *map_checker)
{
	if (map[y][x] != '@' && map[y][x] != '1')
	{
		get_grid_info(map[y][x], map_checker);
		map[y][x] = '@';
		explore_map(map, x+1, y, map_checker);
		explore_map(map, x-1, y, map_checker);
		explore_map(map, x, y+1, map_checker);
		explore_map(map, x, y-1, map_checker);
	}
}

bool match_explored_info(t_game *game, t_chk map_checker)
{
	if (!map_checker.cnt_dot || game->rem_dot != map_checker.cnt_dot)
		return (false);
	else if (map_checker.cnt_exit == 0)
		return (false);
	else if (map_checker.cnt_player > 1)
		return (false);
	return (true);
}

void	check_is_playable_map(t_game *game, const char **src_map)
{
	size_t	init_x;
	size_t	init_y;
	t_chk	map_checker;
	char **cpy_map;

	cpy_map = ft_matrixdup(src_map);
	map_checker = (t_chk){};
	init_x = game->player_coord.x;
	init_y = game->player_coord.y;
	explore_map(cpy_map, init_x, init_y, &map_checker);
	if (match_explored_info(game, map_checker) == false)
		put_error_and_exit(ERR_NOT_PLAYABLE);
	ft_free_matrix(&cpy_map);
}
