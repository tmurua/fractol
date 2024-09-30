/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:00:09 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/30 19:57:22 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	events_handler(t_fractol *fractol)
{
	fractol->event_handler.real_axis = 0;
	fractol->event_handler.imagin_axis = 0;
	fractol->event_handler.scale_zoom = DEFAULT_ZOOM_LEVEL;
	mlx_key_hook(fractol->window_init.mlx_new_window,
		press_keys_handler, fractol);
	mlx_mouse_hook(fractol->window_init.mlx_new_window,
		mouse_handler, fractol);
}

int	press_keys_handler(int keycode, t_fractol *fractol)
{
	if (keycode == ESC)
		close_window(fractol);
	if (keycode == ARROW_UP)
		fractol->event_handler.imagin_axis -= MOVE_IMAGIN_AXIS;
	if (keycode == ARROW_DOWN)
		fractol->event_handler.imagin_axis += MOVE_IMAGIN_AXIS;
	if (keycode == ARROW_LEFT)
		fractol->event_handler.real_axis -= MOVE_REAL_AXIS;
	if (keycode == ARROW_RIGHT)
		fractol->event_handler.real_axis += MOVE_REAL_AXIS;
	render_fractal(fractol);
	return (0);
}

int	mouse_handler(int wheel, int x, int y, t_fractol *fractol)
{
	adjust_zoom(wheel, fractol);
//	adjust_center_position(x, y, fractol);
	(void) x; //delete after implementing adjust_center_position()
	(void) y; //delete after implementing adjust_center_position()
	render_fractal(fractol);
	return (0);
}

void	adjust_zoom(int wheel, t_fractol *fractol)
{
	if (wheel == MOUSE_WHEEL_UP)
		fractol->event_handler.scale_zoom *= 1.1;
	else if (wheel == MOUSE_WHEEL_DOWN)
		fractol->event_handler.scale_zoom *= 0.9;
}

/* make it work!
void	adjust_center_position(int x, int y, t_fractol *fractol)
{
	t_complex_nbr	mouse_two_axis;
	double			real_range;
	double			imagin_range;

	mouse_two_axis = scale_pxl_to_complex(x, y, fractol);
	real_range = (MAX_REAL_AXIS - MIN_REAL_AXIS)
		* fractol->event_handler.scale_zoom;
	imagin_range = (MAX_IMAGIN_AXIS - MIN_IMAGIN_AXIS)
		* fractol->event_handler.scale_zoom;
	fractol->event_handler.real_axis = mouse_two_axis.real
		- (x / (double)WIDTH) * real_range;
	fractol->event_handler.imagin_axis = mouse_two_axis.imagin
		- (y / (double)HEIGHT) * imagin_range;
}
*/
