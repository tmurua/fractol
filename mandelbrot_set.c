/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:28:53 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/29 22:47:53 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iteration(t_complex_nbr c)
{
	t_complex_nbr	z;
	double			temp_real;
	int				iteration;

	z.real = 0;
	z.imagin = 0;
	iteration = 0;
	while ((z.real * z.real + z.imagin * z.imagin <= (2 * 2))
		&& (iteration++ < MAX_ITERATIONS))
	{
		temp_real = z.real * z.real - z.imagin * z.imagin + c.real;
		z.imagin = 2 * z.real * z.imagin + c.imagin;
		z.real = temp_real;
	}
	return (iteration);
}

void	render_mandelbrot(t_fractol *fractol)
{
	int				pxl_x;
	int				pxl_y;
	t_complex_nbr	complex_coord;
	int				iterations;
	int				color;

	pxl_y = 0;
	while (pxl_y++ < HEIGHT)
	{
		pxl_x = 0;
		while (pxl_x++ < WIDTH)
		{
			complex_coord = scale_pxl_to_complex(pxl_x, pxl_y);
			iterations = mandelbrot_iteration(complex_coord);
			color = calculate_color(iterations);
			put_pxl_color_to_img(fractol, pxl_x, pxl_y, color);
		}
	}
	mlx_put_image_to_window(fractol->window_init.mlx_init,
		fractol->window_init.mlx_new_window, fractol->window_init.img, 0, 0);
}
