/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:30:23 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/10 18:52:14 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "minilibx/mlx.h"

#define WIDTH	800
#define	HEIGHT	800

#define NO_ARG "Enter one of the following arguments:\n1. mandelbrot\n2. \
julia with 2 numeric arguments"
#define NO_NUM_ARG "You need to enter 2 numeric arguments for julia set\n"

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)

typedef	struct	s_cmpx
{
	double	re;
	double	im;

}	t_cmpx;
//image is basically a pixel buffer, we fill it with
typedef struct	s_img //gets values from mlx_get_data_addr();
{
	void	*img_ptr; // pointer to image struct with mlx_new_image(void *mlx_ptr (conexion ID), width, height), the user
	//can draw inside the image; and then put an image to a specified window.
	char	*addr; // points to an actual pixels, it points to 1 byte! to change the pix/els in an image
	int		bits_per_pixel; // how many pixels, pixel is an intenger so 32, 4 bytes x 2^8
	int		endian; //not very important;
	int		line_len; // we are going to use it in pixel function;
}	t_img;

// FRACTAL ID
typedef	struct	s_mlx
{
	void	*mlx; 		//mlx_init(); starts the conection, it is screen connection identifier
	void	*mlx_wndow; //mlx_new_window(); is window identifier
	char	*name;		//the text that will be displayed in the window's title
	int		type;
	t_cmpx	j_input;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	t_img	img;
	//hooks

}	t_mlx;

//Funciones de start
int		ft_start_fractol(t_mlx *fractal);
void	ft_fractal_init(t_mlx *fractal);
int		ft_close(t_mlx *fractal);
int		ft_key_hook(int keycode, t_mlx *fractal);
int		ft_mouse_hook(int keycode, int x, int y, t_mlx *fractal);

//==============    Render  =========================================
double  ft_pixel_dist(double min, double max, int total_pix);
double  ft_scale_from_pixel(int pixel, double min, double dist_per_pixel);
void	ft_render(t_mlx *fractal);

//==============   Mandelbrot    ======================================
void    ft_init_mandelbrot(t_mlx *fractal);
int		ft_mandelbrot(t_cmpx c);
t_cmpx	ft_f(t_cmpx num, t_cmpx c);
void	ft_render_mandelbrot(t_mlx *fractal);

//================    Julia    ======================================
int		ft_init_julia(t_mlx *fractal, char *x, char *y);
int		ft_julia(t_cmpx z, t_cmpx c);
t_cmpx	ft_f_j(t_cmpx num, t_cmpx c);
void	ft_render_julia(t_mlx *fractal);

//================== Color ===========================================
int	ft_color_mandel(int iter);
int	ft_color_julia(int iter);
int	ft_create_trgb(int r, int g, int b);

//==================   Utils  ========================================
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int		ft_ispace(char c);
double	ft_atof(char *str);
int		ft_check_input(char *str);
#endif