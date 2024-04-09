/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:30:37 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/09 14:48:09 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//shows where at our scale is a specific pixel
double	pixel_dist(double min, double max, int total_pix)
{
	double	total_dist;
	double	dist_per_pixel;

	total_dist = max - min;
	dist_per_pixel = total_dist / (total_pix - 1);
	return (dist_per_pixel);
}

//shows where at our scale is a specific pixel
double	scale_from_pixel(int pixel, double min, double dist_per_pixel)
{
	return ((dist_per_pixel * pixel) + min);
}

void	render(t_mlx *fractal)
{
	if (fractal->type == 1)
		render_mandelbrot(fractal);
	else if (fractal->type == 2)
		render_julia(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_wndow, fractal->img.img_ptr, 0, 0);
}
