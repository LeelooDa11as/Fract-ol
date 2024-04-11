/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:32:44 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/11 15:19:03 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mandelbrot(t_mlx *fractal)
{
	fractal->name = "mandelbrot";
	fractal->type = 1;
	fractal->x_min = -2;
	fractal->x_max = 0.6;
	fractal->y_min = -1.2;
	fractal->y_max = 1.2;
}

void	ft_render_mandelbrot(t_mlx *fractal, int x, int y)
{
	int		iter;
	double	pixel_dist_y;
	double	pixel_dist_x;
	t_cmpx	res;

	pixel_dist_y = ft_pixel_dist(fractal->y_min, fractal->y_max, HEIGHT);
	pixel_dist_x = ft_pixel_dist(fractal->x_min, fractal->x_max, WIDTH);
	while (y < HEIGHT)
	{
		x = 0;
		res.im = ft_scale_from_pixel(y, fractal->y_min, pixel_dist_y);
		while (x < WIDTH)
		{
			res.re = ft_scale_from_pixel(x, fractal->x_min, pixel_dist_x);
			iter = ft_mandelbrot(res);
			if (iter < 100)
				ft_mlx_pixel_put(&fractal->img, x, y, ft_color_mandel(iter));
			else
				ft_mlx_pixel_put(&fractal->img, x, y, BLACK);
			x++;
		}
		y++;
	}
}

int	ft_mandelbrot(t_cmpx c)
{
	t_cmpx	z;
	int		i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while ((z.re * z.re + z.im * z.im) <= 4 && i < 100)
	{
		z = ft_f(z, c);
		i++;
	}
	return (i);
}

t_cmpx	ft_f(t_cmpx num, t_cmpx c)
{
	double	real_num;
	double	im_num;

	real_num = num.re * num.re - num.im * num.im + c.re;
	im_num = 2 * num.re * num.im + c.im;
	return ((t_cmpx){real_num, im_num});
}
