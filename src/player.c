# include "so_long.h"

# define STS_ALIVE 0 
# define STS_GOAL 1
# define STS_DEAD -1

# define TYPE_NORMAL
# define TYPE_ABNORMAL

typedef struct s_player {
	int		status;
	void*	img;
	void*	next;
}	t_player;

typedef struct s_enemy {
	int		type;
	void*	img; 
	void*	next;
}	t_enemy;


void load_animation(t_game *game)
{
	int i;

	i = 0;
	while (i < IMG_MAX)
	{
		game->img.enemy[i] = convert_file_into_image(game->mlx, ./img/enemy)
		i++;
	}

}