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

//image is basically a pixel buffer, we fill it with
//pixels and push it to our window

typedef struct	s_img //gets values from mlx_get_data_addr();
{
	void	*img_ptr; // pointer to image struct with mlx_new_image(void *mlx_ptr (conexion ID), width, height), the user
	//can draw inside the image; and then put an image to a specified window.
	char	*pixel; // points to an actual pixels, it points to 1 byte! to change the pixels in an image
	int		b_ppixel; // how many pixels, pixel is an intenger so 32, 4 bytes x 2^8
	int		endian; //not very important;
	int		line_len; // we are going to use it in pixel function;
}	t_img;

// FRACTAL ID
typedef	struct	s_mlx
{
	void	*mlx; 		//mlx_init(); starts the conection, it is screen connection identifier
	void	*mlx_wndow //mlx_new_window(); is window identifier
	char	*name;		//the text that will be displayed in the window's title
	//image
	t_img	img;
	//hooks




}	t_mlx;

typedef	struct	s_cmpx
{
	double	re;
	double	im;

}	t_cmpx;

#endif