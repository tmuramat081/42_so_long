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

#include "so_long_bonus.h"
#define CHECKED '@'

void	check_grid_object(char grid, t_chk *map_checker)
{
	if (grid == '0' || grid == 'P' || grid == 'O')
		return ;
	else if (grid == 'C')
		map_checker->exists_collect = true;
	else if (grid == 'E')
		map_checker->exists_exit = true;
	else
		map_checker->is_obj_unknown = true;
}

void	explore_map(char **map, t_vector2 pos, t_chk *map_checker)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (x == -1 || x == map_checker->width_lim
		|| y == -1 || y == map_checker->height_lim)
		map_checker->is_map_opened = true;
	else if (map[y][x] != CHECKED && map[y][x] != '1')
	{
		check_grid_object(map[y][x], map_checker);
		map[y][x] = CHECKED;
		explore_map(map, (t_vector2){x + 1, y}, map_checker);
		explore_map(map, (t_vector2){x - 1, y}, map_checker);
		explore_map(map, (t_vector2){x, y + 1}, map_checker);
		explore_map(map, (t_vector2){x, y - 1}, map_checker);
	}
}

void	check_is_playable_map(t_game *game, t_chk map_checker)
{
	if (map_checker.is_obj_unknown == true)
		handle_process_error(game, ERR_MAP_FMT);
	else if (map_checker.exists_collect == false)
		handle_process_error(game, ERR_MAP_FMT);
	else if (map_checker.exists_exit == false)
		handle_process_error(game, ERR_NOT_PLAYABLE);
	else if (map_checker.is_map_opened == true)
		handle_process_error(game, ERR_NO_WALL);
	return ;
}

void	validate_map_playability(t_game *game, t_clist *character)
{
	t_chk	map_checker;
	char	**cpy_map;

	map_checker = (t_chk){};
	map_checker.width_lim = game->map_width;
	map_checker.height_lim = game->map_height;
	cpy_map = ft_matrixdup((const char **)game->map);
	if (!cpy_map)
		handle_process_error(game, ERR_MEMORY);
	explore_map(cpy_map, character->pos, &map_checker);
	ft_free_matrix(&cpy_map);
	check_is_playable_map(game, map_checker);
}
