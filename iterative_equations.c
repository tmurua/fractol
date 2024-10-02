/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_equations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:28:53 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/02 18:44:50 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	Zₙ₊₁ = Zₙ² + c
	z: point in complex plane that changes in every iteration
	c: complex constant added to Z in every iteration */
t_complex_nbr	polynomial_quadratic_i(t_complex_nbr z, t_complex_nbr c)
{
	t_complex_nbr	next_z;
	t_complex_nbr	z_squared;

	z_squared = square_complex_number(z);
	next_z.real = z_squared.real + c.real;
	next_z.imagin = z_squared.imagin + c.imagin;
	return (next_z);
}

/*	z = [z.real] + [z.imagin*i] // where i is the imaginary unit and  i² = -1
	z² = (z.real + z.imagin*i) * (z.real + z.imagin*i)
	z² = z.real² + (z.real*(z.imagin*i)) + ((z.imagin*i)*z.real) + (z.imagin*i)²
	z² = z.real² + 2*(z.real*z.imagin*i) + (z.imagin² * i²)
	z² = z.real² + (2 * z.real * z.imagin*i) - (z.imagin²) // i² = -1!!!
	z² = [z.real² - z.imagin²] + [(2 * z.real * z.imagin)*i]	*/
t_complex_nbr	square_complex_number(t_complex_nbr z)
{
	t_complex_nbr	z_squared;

	z_squared.real = z.real * z.real - z.imagin * z.imagin;
	z_squared.imagin = 2 * z.real * z.imagin;
	return (z_squared);
}

/*	set nbr of iterations required for point c (current pxl scaled to complex
	plane) to exceed the radius squared (2²):
	for Zₙ₊₁ = Zₙ² + c, if |Z| exceeds 2, the sequence will escape to infinity
	the mandelbrot set is the set for which the sequence remains bounded	*/
int	mandelbrot_iteration(t_complex_nbr c)
{
	t_complex_nbr	z;
	int				iteration;

	z.real = 0;
	z.imagin = 0;
	iteration = 0;
	while ((z.real * z.real + z.imagin * z.imagin <= (2 * 2))
		&& (iteration++ < MAX_ITERATIONS))
		z = polynomial_quadratic_i(z, c);
	return (iteration);
}

/*	set nbr of iterations required for point z (current pxl scaled to complex
	plane) to exceed the radius squared (2²)
	Z₀ is the initial complex coordinate of the current pixel.
	c is the constant complex number parsed by the user on fractol->julia_c
	for a fixed complex number C, it's the set of complex numbers Z₀
	it generates different fractal patterns based on the chosen constant c	*/
int	julia_iteration(t_complex_nbr z, t_fractol *fractol)
{
	int				iteration;

	iteration = 0;
	while (iteration < MAX_ITERATIONS)
	{
		z = polynomial_quadratic_i(z, fractol->julia_c);
		iteration++;
		if ((z.real * z.real + z.imagin * z.imagin) > 4)
			break ;
	}
	return (iteration);
}
