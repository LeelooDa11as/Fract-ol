#include "fractol.h"

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
	return (t_cmpx{real_num, im_num});
	}