/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:40:36 by tmuramat          #+#    #+#             */
/*   Updated: 2022/04/12 18:40:36 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

/* "./ber" is prohibited as invalid file name. */
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

/* Count the number of collect, and locate player spawn point. */
void	parse_grid_object(char *map_line, size_t y, t_game *game)
{
	size_t	x;

	x = 0;
	while (map_line[x])
	{
		if (map_line[x] == 'C')
			game->cnt_collect += 1;
		else if (map_line[x] == 'P')
			character_lstnew(&game->character, (t_vector2){x, y}, TYPE_PLAYER);
		else if (map_line[x] == 'O')
			character_lstnew(&game->character, (t_vector2){x, y}, TYPE_ENEMY);
		x++;
	}
}

/* Check if the map is rectangular or square. */
void	parse_line_size(char *map_line, t_game *game)
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
char	**load_map_file(char *file, t_game *game)
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
			return (map);
		parse_line_size(map[i], game);
		parse_grid_object(map[i], i, game);
		i++;
	}
	return (NULL);
}
