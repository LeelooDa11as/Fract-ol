#include "fractol.h"

//Iniciation

void    fractal_init(t_mlx fractal)
{
    fractal->mlx = mlx_init(); //to start the conexion
    if (fractal->mlx == NULL) // tiene que devolver un puntero void
        //return error y libera
    fractal->mlx_wndw = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx->wndw == NULL) // we have to destroy the created display
    {
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        //malloc_error();
    }
    //we need to create a new image mlx_new_image(void *mlx_ptr, int width, int height)
    // this function returns a vois ptr to later manipulate the image it need a connection
    //identifier and parameters of width and height, the user can draw inside the image
    //and then put it inside a specified window to display on a screen by mlx_put_image_to_window;
    fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (fractal->img.img_ptr == NULL)
    {
        mlx_destroy_window()
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        //malloc_error();
    }

}


//listening events

//hooks data

