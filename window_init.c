/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:18:30 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/01 18:45:52 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* init MLX window, sets up hook to close window, create img buffer */
void	window_init(t_fractol *fractol)
{
	fractol->window_init.mlx_init = mlx_init();
	fractol->window_init.mlx_new_window
		= mlx_new_window(fractol->window_init.mlx_init, WIDTH, HEIGHT,
			fractol->name);
	mlx_hook(fractol->window_init.mlx_new_window,
		17, 0, close_window, fractol);
	create_image_buffer(fractol);
}

/* create img buffer with same width and height as the window */
void	create_image_buffer(t_fractol *fractol)
{
	fractol->window_init.img = mlx_new_image(fractol->window_init.mlx_init,
			WIDTH, HEIGHT);
	fractol->window_init.addr = mlx_get_data_addr(fractol->window_init.img,
			&fractol->window_init.bits_per_pixel,
			&fractol->window_init.bytes_per_vertical_line,
			&fractol->window_init.endian);
}

/* cleans up everything and exits the program after window is closed */
int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->window_init.mlx_init, fractol->window_init.img);
	mlx_destroy_window(fractol->window_init.mlx_init,
		fractol->window_init.mlx_new_window);
	mlx_destroy_display(fractol->window_init.mlx_init);
	free(fractol->window_init.mlx_init);
	exit(0);
}
