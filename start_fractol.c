/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:34:08 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/11 15:37:43 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_fractal_init(t_mlx *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		return (0);
	fractal->mlx_wndow = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, \
	fractal->name);
	if (fractal->mlx_wndow == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_wndow);
		free(fractal->mlx);
		return (0);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
		mlx_destroy_window(fractal->mlx, fractal->mlx_wndow);
		free(fractal->mlx);
		return (0);
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr, \
	&fractal->img.bits_per_pixel, &fractal->img.line_len, &fractal->img.endian);
	ft_render(fractal);
	return (1);
}

int	ft_key_hook(int keycode, t_mlx *fractal)
{
	if (keycode == 53)
		ft_close(fractal);
	return (0);
}

int	ft_mouse_hook(int keycode, int x, int y, t_mlx *fractal)
{
	x = 0;
	y = 0;
	if (keycode == 4)
	{
		fractal->x_min = fractal->x_min * 1.1 + x;
		fractal->y_min = fractal->y_min * 1.1 + y;
		fractal->x_max = fractal->x_max * 1.1 + x;
		fractal->y_max = fractal->y_max * 1.1 + y;
	}
	else if (keycode == 5)
	{
		fractal->x_min = fractal->x_min / 1.1 + x;
		fractal->y_min = fractal->y_min / 1.1 + y;
		fractal->x_max = fractal->x_max / 1.1 + x;
		fractal->y_max = fractal->y_max / 1.1 + y;
	}
	mlx_clear_window(fractal->mlx, fractal->mlx_wndow);
	ft_render(fractal);
	return (0);
}

int	ft_close(t_mlx *fractal)
{
	if (fractal->mlx_wndow)
		mlx_destroy_window(fractal->mlx, fractal->mlx_wndow);
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	exit (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	fractal;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) \
	&& ft_strlen(argv[1]) == 10)
		ft_init_mandelbrot(&fractal);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5) && \
	ft_strlen(argv[1]) == 5)
	{
		if (ft_init_julia(&fractal, argv[2], argv[3]) == 0)
			return (0);
	}
	else
	{
		ft_putstr_fd(NO_ARG, 2);
		exit (0);
	}
	if (ft_fractal_init(&fractal) == 0)
		return (0);
	mlx_key_hook(fractal.mlx_wndow, ft_key_hook, &fractal);
	mlx_mouse_hook(fractal.mlx_wndow, ft_mouse_hook, &fractal);
	mlx_hook(fractal.mlx_wndow, 17, 0, ft_close, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
