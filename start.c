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
void    init_mandelbrot(t_mlx *fractal, char* name)
{
    fractal->name = name;
    fractal->type = 1;
    fractal->x_min = -2;
	fractal->x_max = 0.6;
	fractal->y_min = -1.2;
	fractal->y_max = 1.2;
}


//listening events

//hooks data

