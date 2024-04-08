#include "fractol.h"

/*void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int pixel;

	pixel = (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(int *)(img->addr + pixel) = color;
}*/

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}