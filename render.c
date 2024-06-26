/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:30:37 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/11 15:38:44 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//shows where at our scale is a specific pixel
double	ft_pixel_dist(double min, double max, int total_pix)
{
	double	total_dist;
	double	dist_per_pixel;

	total_dist = max - min;
	dist_per_pixel = total_dist / (total_pix - 1);
	return (dist_per_pixel);
}

//shows where at our scale is a specific pixel
double	ft_scale_from_pixel(int pixel, double min, double dist_per_pixel)
{
	return ((dist_per_pixel * pixel) + min);
}

void	ft_render(t_mlx *fractal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (fractal->type == 1)
		ft_render_mandelbrot(fractal, x, y);
	else if (fractal->type == 2)
		ft_render_julia(fractal, x, y);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_wndow, \
	fractal->img.img_ptr, 0, 0);
}

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
