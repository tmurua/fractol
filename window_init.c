/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:18:30 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/30 17:54:04 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_init(t_fractol *fractol)
{
	fractol->window_init.mlx_init = mlx_init();
	fractol->window_init.mlx_new_window
		= mlx_new_window(fractol->window_init.mlx_init, WIDTH, HEIGHT,
			fractol->name);
	mlx_hook(fractol->window_init.mlx_new_window,
		17, 0, close_window, fractol);
	create_image(fractol);
}

int	close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->window_init.mlx_init, fractol->window_init.img);
	mlx_destroy_window(fractol->window_init.mlx_init,
		fractol->window_init.mlx_new_window);
	mlx_destroy_display(fractol->window_init.mlx_init);
	free(fractol->window_init.mlx_init);
	exit(0);
}
