#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	main(void)
{
	t_vars	vars;
	void	*mlx;
	void	*img;
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "./img/xpm.xpm", &img_width, &img_height);
//	mlx_put_image_to_window(vars.mlx, vars.win, img, 320, 240); 
	mlx_loop(vars.mlx);
	return (0);
}