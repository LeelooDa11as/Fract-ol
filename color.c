#include "fractol.h"

int	ft_color_mandelbrot(int iter)
{
    return (ft_create_trgb(iter * 15, 50, 100 + iter * 5));

}

int	ft_color_julia(int iter)
{
    return (ft_create_trgb(iter * 7, 20, 10 + iter * 5));
}

int	ft_create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}