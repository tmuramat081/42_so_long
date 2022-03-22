#include "so_long.h"

char **load_map_file(char *file)
{
	int		fd;
	char	**map;
	int 	i;

	map = malloc(sizeof(char *) * MAP_SIZE_MAX);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < MAP_SIZE_MAX)
	{
		map[i] = get_next_line(fd);
		printf("%s", map[i]);
		if (!map[i])
			break ;
		i++;
	}
	close(fd);
	return (map);
}
