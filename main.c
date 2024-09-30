/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:03:02 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/30 15:10:27 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)
				|| !ft_strncmp(argv[1], "burning", 7)))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		window_init(&fractol);
		render_fractal(&fractol);
		events_handler(&fractol);
		mlx_loop(fractol.window_init.mlx_init);
	}
	else
		wrong_input();
}

void	wrong_input(void)
{
	ft_printf("Enter:\n./fractol mandelbrot\n./fractol julia x y\n");
	ft_printf("./fractol burning\n");
	exit(EXIT_FAILURE);
}

/*
5. Set up mouse events using MiniLibX functions
	- Implement mouse wheel zoom in and out
	- Implement zoom following the actual mouse position
*/
