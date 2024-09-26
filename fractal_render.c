/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:14:24 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/26 23:51:57 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	map_coords_to_plane(t_fractol *fractol)
{
	int		x;
	int		y;
	double	real;
	double	imagin;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = fractol->fractal_render.min_real + (x / (double)WIDTH)
				* (fractol->fractal_render.max_real
					- fractol->fractal_render.min_real);
			imagin = fractol->fractal_render.min_imagin + (y / (double)HEIGHT)
				* (fractol->fractal_render.max_imagin
					- fractol->fractal_render.min_imagin);
			x++;
		}
		y++;
	}
}

void	initialize_fractal(t_fractol *fractol)
{
	fractol->fractal_render.min_real = -2.0;
	fractol->fractal_render.max_real = 2.0;
	fractol->fractal_render.min_imagin = -1.5;
	fractol->fractal_render.max_imagin = 1.5;
	fractol->fractal_render.zoom_level = 1.0;
	fractol->fractal_render.iterations = 50;
}
