/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:00:09 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/01 20:05:45 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* init event handlers for key and mouse inputs */
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

/* handle key press events for navigation and close window */
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
	(void) x;
	(void) y;
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
