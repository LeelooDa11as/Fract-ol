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
    //events_init(fractal);
    //data_init(fractal);

}

//listening events

//hooks data


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
	//mlx_key_hook(fractal.mlx_wndow, key_hook, &vars);
	mlx_loop(fractal.mlx);
	return (0);
}
