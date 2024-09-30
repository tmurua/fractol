/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:14:24 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/29 14:12:13 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "mandelbrot", 10))
		render_mandelbrot(fractol);
//	if (!ft_strncmp(fractol->name, "julia", 5))
//		render_julia(&fractol);
//	if (!ft_strncmp(fractol->name, "burning", 7))
//		render_burning(&fractol);
}

void	create_image(t_fractol *fractol)
{
	fractol->window_init.img = mlx_new_image(fractol->window_init.mlx_init,
			WIDTH, HEIGHT);
	fractol->window_init.addr = mlx_get_data_addr(fractol->window_init.img,
			&fractol->window_init.bits_per_pixel,
			&fractol->window_init.line_length, &fractol->window_init.endian);
}

t_complex_nbr	scale_pxl_to_complex(int pxl_x, int pxl_y, t_fractol *fractol)
{
	t_complex_nbr	complex_coord;
	double			real_range;
	double			imagin_range;

	real_range = (MAX_REAL_AXIS - MIN_REAL_AXIS)
		* fractol->event_handler.scale_zoom;
	imagin_range = (MAX_IMAGIN_AXIS - MIN_IMAGIN_AXIS)
		* fractol->event_handler.scale_zoom;
	complex_coord.real = MIN_REAL_AXIS + fractol->event_handler.real_axis
		+ (pxl_x / (double)WIDTH) * real_range;
	complex_coord.imagin = MIN_IMAGIN_AXIS + fractol->event_handler.imagin_axis
		+ (pxl_y / (double)HEIGHT) * imagin_range;
	return (complex_coord);
}

int	calculate_color(int iterations)
{
	if (iterations >= MAX_ITERATIONS)
		return (BLACK);
	return (PINK * iterations * MAX_ITERATIONS);
}

void	put_pxl_color_to_img(t_fractol *f, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = f->window_init.addr
			+ (y * f->window_init.line_length)
			+ (x * (f->window_init.bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}
