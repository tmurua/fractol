/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:00:09 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/26 09:09:05 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	event_handler(t_fractol *fractol)
{
	mlx_hook(fractol->window_init.addr, key_code, key_mask, mouse_handler,
		fractol);
	fractol->event_handler.mouse_x;
	fractol->event_handler.mouse_y;
	if (key_code == 4)
		zoom();
	else if (key_code == 5)
		zoom();
}
