/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:22:35 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/15 14:22:35 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line.h"

/* "./ber" is regaeded as invalid file name. */
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

/* Count the number of collectibles, and locate character's spawn point. */
void	parse_grid_object(char *map_line, size_t y, t_game *game)
{
	size_t	x;

	x = 0;
	while (map_line[x])
	{
		if (map_line[x] == 'C')
			game->cnt_collect += 1;
		else if (map_line[x] == 'P')
			character_lstnew(game, (t_vector2){x, y}, TYPE_PLAYER);
		else if (map_line[x] == 'O')
			character_lstnew(game, (t_vector2){x, y}, TYPE_ENEMY);
		x++;
	}
}


/* Check if the map is rectangular or square. */
void	measure_map_size(char **map, size_t i, t_game *game)
{
	if (i == 0)
		game->map_width = ft_strcspn(map[0], "\n\r");
	if (game->map_height > MAP_HEIGHT_MAX)
		handle_error(game, ERR_MAP_SIZE);
	if (game->map_width > MAP_WIDTH_MAX)
		handle_error(game, ERR_MAP_SIZE);
	else if (game->map_width != ft_strcspn(map[i], "\n\r"))
		handle_error(game, ERR_MAP_FMT);
	game->map_height += 1;
}

void	parse_map(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map[i])
	{
		measure_map_size(game->map, i, game);
		parse_grid_object(game->map[i], i, game);
		i++;
	}
}

/* Read a map file line by line, using get_next_line(subject of school 42). */
void	load_map_file(char *file, t_game *game)
{
	int		fd;
	size_t	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	game->map = malloc(sizeof(char *) * MAP_HEIGHT_MAX + 1);
	if (!game->map)
		return ;
	i = 0;
	while (i < MAP_HEIGHT_MAX)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
		i++;
	}
	close(fd);
}
