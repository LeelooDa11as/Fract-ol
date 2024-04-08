/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoval <kkoval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:37:17 by kkoval            #+#    #+#             */
/*   Updated: 2024/04/08 17:40:11 by kkoval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_julia(t_mlx *fractal, char* name)
{
    fractal->name = name;
    fractal->type = 2;
    fractal->j_x = ;
    fractal->j_x = ;
    fractal->x_min = -2;
	fractal->x_max = 0.6;
	fractal->y_min = -1.2;
	fractal->y_max = 1.2;
}

void	*mlx; 		//mlx_init(); starts the conection, it is screen connection identifier
	void	*mlx_wndow; //mlx_new_window(); is window identifier
	char	*name;		//the text that will be displayed in the window's title
	int		type;
	double	j_x;
	double	j_y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	t_img	img;