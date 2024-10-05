/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:03:02 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/05 17:33:18 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* user should input args to choose which fractal to render */
int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!input_arguments(argc, argv, &fractol))
		return (EXIT_FAILURE);
	fractol_init(&fractol);
	mlx_loop(fractol.window_init.mlx_init);
	return (EXIT_SUCCESS);
}

int	input_arguments(int argc, char **argv, t_fractol*fractol)
{
	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 11)))
	{
		fractol->name = argv[1];
		return (1);
	}
	else if ((argc == 4 && !ft_strncmp(argv[1], "julia", 6)
			&& (!ft_strncmp(argv[2], "0", 1)
				|| (!ft_strncmp(argv[2], "-", 1))
				|| (!ft_strncmp(argv[2], "1", 1)))
			&& (!ft_strncmp(argv[3], "0", 1)
				|| (!ft_strncmp(argv[3], "-", 1))
				|| (!ft_strncmp(argv[3], "1", 1)))))
	{
		fractol->name = argv[1];
		fractol->julia_c.real = ft_atof(argv[2]);
		fractol->julia_c.imagin = ft_atof(argv[3]);
		return (1);
	}
	else
	{
		wrong_input();
		return (0);
	}
}

void	fractol_init(t_fractol *fractol)
{
	window_init(fractol);
	render_fractal(fractol);
	events_handler(fractol);
}

/* instructions to the user if incorrect input is passed */
void	wrong_input(void)
{
	ft_printf("Enter:\n./fractol mandelbrot\n");
	ft_printf("./fractol julia <real part> <imaginary part>\n");
	exit(EXIT_FAILURE);
}
