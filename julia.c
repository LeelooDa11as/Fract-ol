/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:37:17 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/11 15:18:48 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_init_julia(t_mlx *fractal, char *x, char *y)
{
	double	re;
	double	im;

	if (!ft_check_input(x) || !ft_check_input(y))
	{
		ft_putstr_fd(NO_NUM_ARG, 2);
		return (0);
	}
	re = ft_atof(x);
	im = ft_atof(y);
	if ((re > 2 || re < -2) || im > 2 || im < -2)
		return (0);
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

void	ft_render_julia(t_mlx *fractal, int x, int y)
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
			iter = ft_julia(res, fractal->j_input);
			if (iter < 500)
				ft_mlx_pixel_put(&fractal->img, x, y, ft_color_julia(iter));
			else
				ft_mlx_pixel_put(&fractal->img, x, y, BLACK);
			x++;
		}
		y++;
	}
}

int	ft_julia(t_cmpx z, t_cmpx c)
{
	int	i;

	i = 0;
	while ((z.re * z.re + z.im * z.im) <= 4 && i < 500)
	{
		z = ft_f_j(z, c);
		i++;
	}
	return (i);
}

t_cmpx	ft_f_j(t_cmpx num, t_cmpx c)
{
	double	real_num;
	double	im_num;

	real_num = num.re * num.re - num.im * num.im + c.re;
	im_num = 2 * num.re * num.im + c.im;
	return ((t_cmpx){real_num, im_num});
}
