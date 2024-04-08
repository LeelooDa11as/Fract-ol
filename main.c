#include "fractol.h"

//EVENTS
/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	clos(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, clos, &vars);
	mlx_loop(vars.mlx);
}*/


//HOOKS
/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("Hello from mouse_hook! %d\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}*/


//Pintar pixels
/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int 	x = 400;
	int		y = 400;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1020, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x < 500)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		my_mlx_pixel_put(&img, x, 500, 0x00FF0000);
		x++;
		
	}
	while (y < 500)
	{
		my_mlx_pixel_put(&img, 400, y, 0x0b94e3);
		my_mlx_pixel_put(&img, 500, y, 0x0b94e3);
		y++;
	}
	x = 500;
	while (600 < 900 && )
	{
		my_mlx_pixel_put(&img, 400, y, 0x0b94e3);
	}
	//my_mlx_pixel_put(&img, y, 6, 0x0b94e3);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
*/

int main(int argc, char *argv[])
{
	t_mlx	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		init_mandelbrot(&fractal, argv[1]);
	else if(argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		fractal.type = 2;
		//controlar mejor el input que no sean letras y mierdas
		fractal.j_x = ft_atoi(argv[2]);
		fractal.j_y = ft_atoi(argv[3]);
		printf("fractal name is -->%s\n", fractal.name);
	}
	else
	{
		if (argc == 2 && !ft_strncmp(argv[1], "julia", 5))
			ft_putstr_fd("Please enter enter the 2 numbers if you choose julia", 2);
		else
			ft_putstr_fd("Please enter one of the following:\n1. mandelbrot\n2. julia with 2 numbers ", 2);
		exit (0); // Exit failure
	}
	fractal_init(&fractal);
	render(&fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.mlx_wndow, fractal.img.img_ptr, 0, 0);
	mlx_loop(fractal.mlx);
	return (0);
}