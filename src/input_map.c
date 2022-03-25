#include "so_long.h"

void	parse_map(t_game *game, char **map)
{
	size_t i;
	size_t j;

	i = 0;
	game->map_width = ft_strcspn(map[0], "\n");
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				game->player_coord.y = i;
				game->player_coord.x = j;
			}
			j++;
		}
		i++;
	}
	game->map_height = i;
}

char **load_map_file(char *file)
{
	int		fd;
	char	**map;
	size_t	i;

	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * MAP_SIZE_MAX + 1);
	i = 0;
	while (true)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	return (map);
}

void input_map(t_game *game, char *map_file)
{
	char **map;

	if (is_valid_file_name(map_file) == false)
		put_error_and_exit(ERR_FILE_NAME);
	map = load_map_file(map_file);
	parse_map(game, map);
	if (is_valid_map(map) == false)
		put_error_and_exit("Error");
	game->map = map;
}