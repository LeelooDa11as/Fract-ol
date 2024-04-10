/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:37:17 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/10 18:51:11 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_julia(t_mlx *fractal, char *x, char *y)
{
	double	re;
	double	im;

	if (!check_input(x) || !check_input(y))
	{
		ft_putstr_fd(NO_NUM_ARG, 2);
		return(0);
	}
	re = ft_atof(x);
	im = ft_atof(y); 
	fractal->name = "julia";
	fractal->type = 2;
	fractal->j_input.re = re;
	fractal->j_input.im = im;
	fractal->x_min = -2;
	fractal->x_max = 2;
	fractal->y_min = -2;
	fractal->y_max = 2;
	return (1);
}

void	render_julia(t_mlx *fractal)//27 lines and too many variable declared.
{
	int		y;
	int		x;
	int		iter;
	double	pixel_dist_y;
	double	pixel_dist_x;
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
			iter = julia(res, fractal->j_input);
			if (iter < 500)
				ft_mlx_pixel_put(&fractal->img, x, y, ft_color_julia(iter));
			else
				ft_mlx_pixel_put(&fractal->img, x, y, BLACK);
			x++;
		}
		y++;
	}
}

int	julia(t_cmpx z, t_cmpx c)
{
	int	i;

	i = 0;
	while ((z.re * z.re + z.im * z.im) <= 4 && i < 500)
	{
		z = f_julia(z, c);
		i++;
	}
	return (i);
}

t_cmpx	f_julia(t_cmpx num, t_cmpx c)
{
	double	real_num;
	double	im_num;

	real_num = num.re * num.re - num.im * num.im + c.re;
	im_num = 2 * num.re * num.im + c.im;
	return ((t_cmpx){real_num, im_num});
}
