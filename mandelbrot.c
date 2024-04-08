#include "fractol.h"

void	render_mandelbrot(t_mlx *fractal)
{
	int		y;
	int		x;
	int		iter;
	double 	pixel_dist_y;
	double 	pixel_dist_x;
	t_cmpx	res;

	y = 0;

	pixel_dist_y = pixel_dist(fractal->y_min, fractal->y_max, HEIGHT);
	pixel_dist_x = pixel_dist(fractal->x_min, fractal->x_max, WIDTH);
	while (y < HEIGHT)
	{
		x = 0;
		res.im = scale_from_pixel(y, fractal->y_min, pixel_dist_y);
		while (x < WIDTH)
		{
			res.re = scale_from_pixel(x, fractal->x_min, pixel_dist_x);
			iter = mandelbrot(res);
			if (iter < 100)
				ft_mlx_pixel_put(&fractal->img, x, y, ft_color(iter));
			else
				ft_mlx_pixel_put(&fractal->img, x, y, BLACK);
			x++;
		}
		y++;
	}
}

int	mandelbrot(t_cmpx c)
{
	t_cmpx	z;
	int		i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while ((z.re * z.re + z.im * z.im) <= 4 && i < 100)
	{
		z = f(z, c);
		i++;
	}
	return (i);
}

t_cmpx f(t_cmpx num, t_cmpx c)
{
	double	real_num;
	double	im_num;

	real_num = num.re * num.re - num.im * num.im + c.re;
	im_num = 2 * num.re * num.im + c.im;
	return ((t_cmpx){real_num, im_num});
}