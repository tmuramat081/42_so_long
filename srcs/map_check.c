/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:31:17 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:31:17 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* "./ber" is treated as invalid file name. */
bool	is_valid_file_name(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (false);
	else if (file_name[len - 5] != '/'
		&& ft_strncmp(&file_name[len - 4], ".ber", 4) == 0)
		return (true);
	return (false);
}

void	get_grid_info(char grid, t_chk *map_checker)
{
	if (grid == '0' || grid == 'P' || grid == 'O')
		return ;
	else if (grid == 'C')
		map_checker->cnt_dot += 1;
	else if (grid == 'E')
		map_checker->cnt_exit += 1;
	else
		put_error_and_exit(ERR_NO_READ);
}

void	explore_map(char **map, t_vector2 pos, t_chk *map_checker)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (x == -1 || x == map_checker->width_lim
		|| y == -1 || y == map_checker->height_lim)
		put_error_and_exit(ERR_NO_WALL);
	else if (map[y][x] != '@' && map[y][x] != '1')
	{
		get_grid_info(map[y][x], map_checker);
		map[y][x] = '@';
		explore_map(map, (t_vector2){x + 1, y}, map_checker);
		explore_map(map, (t_vector2){x - 1, y}, map_checker);
		explore_map(map, (t_vector2){x, y + 1}, map_checker);
		explore_map(map, (t_vector2){x, y - 1}, map_checker);
	}
}

bool	compare_explored_map(t_game *game, t_chk map_checker)
{
	if (!map_checker.cnt_dot || game->cnt_dot != map_checker.cnt_dot)
		return (false);
	else if (map_checker.cnt_exit == 0)
		return (false);
	return (true);
}

void	check_is_playable_map(t_game *game, const char **src_map)
{
	t_chk	map_checker;
	char	**cpy_map;

	map_checker = (t_chk){};
	map_checker.width_lim = game->map_width;
	map_checker.height_lim = game->map_height;
	cpy_map = ft_matrixdup(src_map);
	explore_map(cpy_map, game->character->pos, &map_checker);
	if (compare_explored_map(game, map_checker) == false)
		put_error_and_exit(ERR_NOT_PLAYABLE);
	ft_free_matrix(&cpy_map);
}
