/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:03:02 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/25 11:12:16 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	//t_fractol	fractol;

	if ((argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 10)
				|| !ft_strncmp(argv[1], "burning", 7)))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
			write(1, "rendering mandelbrot\n", 21);
			// render mandelbrot with right parameters
		if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
			write(1, "rendering julia\n", 16);
			// render julia with argv[2] and argv[3] as real and i of constant
		if (argc == 2 && !ft_strncmp(argv[1], "burning", 7))
			write(1, "rendering burning\n", 18);
			// render burning with right parameters
	}
	else
	{
		write(1, "Enter:\n./fractol mandelbrot\n./fractol julia x y\n", 48);
		write(1, "./fractol burning\n", 18);
		exit(EXIT_FAILURE);
	}
/*
2.c- If parameter "burning" is passed as argv[1], render Burning Ship fractal
	- Use correct parameters for each field of the fractal
	- Include color depth representatio
3. Initialize window with appropriate MiniLibX function
	- Include handling of window close event (clicking the close button)
	- Ensure smooth window management (responsive when switching/minimizing)
4. Initialize image with appropriate MiniLibX function (likely needs a buffer)
5. Set up mouse events using MiniLibX functions
	- Implement mouse wheel zoom in and out
	- Implement zoom following the actual mouse position
6. Set up keyboard events using MiniLibX functions
	- Implement pressing ESC key to close window and quit program
	- Implement arrow keys to move the view (navigation)
7. Start event loop
8. Clean up resources on exit */
}
