/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:34:08 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/08 17:36:41 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//If malloc goes bad
static void malloc_error(void)
{
    printf("problems with malloc\n");
}

//Iniciation
void    fractal_init(t_mlx *fractal)
{
    fractal->mlx = mlx_init(); //to start the conexion
    if (fractal->mlx == NULL) // tiene que devolver un puntero void
        malloc_error();
    fractal->mlx_wndow = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_wndow == NULL) // we have to destroy the created display
    {
        mlx_destroy_window(fractal->mlx, fractal->mlx_wndow);
        //mlx_destroy_display(fractal->mlx); esta funcion no existe en esta version
        free(fractal->mlx);
        malloc_error();
    }
    //we need to create a new image mlx_new_image(void *mlx_ptr, int width, int height)
    // this function returns a vois ptr to later manipulate the image it need a connection
    //identifier and parameters of width and height, the user can draw inside the image
    //and then put it inside a specified window to display on a screen by mlx_put_image_to_window;
    fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
        mlx_destroy_window(fractal->mlx, fractal->mlx_wndow);
        free(fractal->mlx);
        malloc_error();
    }
    //this function returns information about the created image, allowing a user to modify it later.
    //The img_ptr parameter specifies the image to use. 3 parameters should be the addresses of three different valid integers.
    //mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
    fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_per_pixel, &fractal->img.line_len, &fractal->img.endian);
    render(fractal);

    //events_init(fractal);
    //data_init(fractal);

}

//listening events

	void	*mlx; 		//mlx_init(); starts the conection, it is screen connection identifier
	void	*mlx_wndow; //mlx_new_window(); is window identifier
	char	*name;		//the text that will be displayed in the window's title
	int		type;
	t_cmpx	j_input;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
//hooks data

int	key_hook(int keycode, t_mlx *fractal)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	mouse_hook(int keycode, t_mlx *fractal)
{
    if (keycode == 4)
    {
        fractal->x_min = fractal->x_min * 1.1;
        fractal->y_min = fractal->y_min * 1.1;
        fractal->x_max = fractal->x_max * 1.1;
        fractal->y_max = fractal->y_max * 1.1;
    }
    else if (keycode == 5)
    {

        fractal->x_min = fractal->x_min / 1.1;
        fractal->y_min = fractal->y_min / 1.1;
        fractal->x_max = fractal->x_max / 1.1;
        fractal->y_max = fractal->y_max / 1.1;
    }
    render(fractal);
	return (0);
}

int	ft_close(t_mlx *fractal)
{
	if (fractal->mlx_wndow)
		mlx_destroy_window(fractal->mlx, fractal->mlx_wndow);
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	exit (0);
}

int main(int argc, char *argv[])
{
	t_mlx	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		init_mandelbrot(&fractal, argv[1]);
	else if(argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
        init_julia(&fractal, argv[1]);
		//printf("fractal name is -->%s\n", fractal.name);
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
    mlx_hook(fractal.mlx_wndow, 17, 0, ft_close, &fractal);
	mlx_key_hook(fractal.mlx_wndow, key_hook, &fractal);
	mlx_mouse_hook(fractal.mlx_wndow, mouse_hook, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
