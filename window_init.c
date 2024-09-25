/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:18:30 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/25 14:12:20 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_init(t_fractol *fractol)
{
	fractol->window_init.mlx_init = mlx_init();
	fractol->window_init.mlx_new_window = mlx_new_window(fractol->window_init.mlx_init, 800, 600, )
	mlx_loop();
}
