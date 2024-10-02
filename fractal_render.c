/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:14:24 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/02 18:42:24 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* render fractal by iterating over each pxl(processed with selected fractal) */
void	render_fractal(t_fractol *fractol)
{
	int	pxl_x;
	int	pxl_y;

	pxl_y = 0;
	while (pxl_y < HEIGHT)
	{
		pxl_x = 0;
		while (pxl_x < WIDTH)
		{
			process_pixel(pxl_x, pxl_y, fractol);
			pxl_x++;
		}
		pxl_y++;
	}
	mlx_put_image_to_window(fractol->window_init.mlx_init,
		fractol->window_init.mlx_new_window,
		fractol->window_init.img, 0, 0);
}

/*	process a single pixel by calculating its corresponding complex coord and
	assign its color based on the fractal iteration */
void	process_pixel(int pxl_x, int pxl_y, t_fractol *fractol)
{
	t_complex_nbr	complex_coord;
	int				iterations;
	int				color;

	complex_coord = scale_pxl_to_complex(pxl_x, pxl_y, fractol);
	if (!ft_strncmp(fractol->name, "mandelbrot", 10))
		iterations = mandelbrot_iteration(complex_coord);
	else if (!ft_strncmp(fractol->name, "julia", 5))
		iterations = julia_iteration(complex_coord, fractol);
	color = calculate_color(iterations);
	put_pxl_color_to_img(fractol, pxl_x, pxl_y, color);
}

/* maps a pixel's screen coords and scales it to a point in the complex plane */
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

/*	assign color of a pixel based on nbr of iterations it took to escape,
	if it never escapes, it's black */
int	calculate_color(int iterations)
{
	if (iterations >= MAX_ITERATIONS)
		return (BLACK);
	return (PINK * iterations * MAX_ITERATIONS);
}

/* sets color of specific pxl in img buffer at coordinates pxl_x, pxl_y */
void	put_pxl_color_to_img(t_fractol *f, int pxl_x, int pxl_y, int color)
{
	char	*pxl_xy;
	int		bytes_per_pixel;
	int		axis_x_offset;
	int		axis_y_offset;

	bytes_per_pixel = f->window_init.bits_per_pixel / 8;
	axis_x_offset = pxl_x * bytes_per_pixel;
	axis_y_offset = pxl_y * f->window_init.bytes_per_vertical_line;
	pxl_xy = f->window_init.addr + axis_x_offset + axis_y_offset;
	*(unsigned int *)pxl_xy = color;
}
