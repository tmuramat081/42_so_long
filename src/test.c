#include <mlx.h>
#include <stdio.h>

char g_map[6][12] = {
{"11111111111"},
{"1E000000001"},
{"10100101001"},
{"10100100101"},
{"1P0000000C1"},
{"11111111111"}
};

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


void	print_map(t_vars *vars)
{
	int i;
	int j;
	int img_width1 = 10;
	int img_height1 = 10;
	int img_width2 = 10;
	int img_height2 = 10;
	void *img1;
	void *img2;
	void *img3;

	img1 = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm", &img_width1, &img_height1);
	img2 = mlx_xpm_file_to_image(vars->mlx, "./img/back.xpm", &img_width2, &img_height2);
	img3 = mlx_xpm_file_to_image(vars->mlx, "./img/player.xpm", &img_width2, &img_height2);
	i = 0;
	while(i < 6)
	{
		j = 0;
		while(j < 11)
		{
			if (g_map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img1, j * 50, i * 50);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, img2, j * 50, i * 50);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img3, 300, 200);
}

int	main(void)
{
	t_vars	vars;
	void	*mlx;
	int		img_width = 50;
	int		img_height = 50;
	void	*img[2];

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 550, 300, "Hello world!");
	print_map(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
