/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:51:12 by tmurua            #+#    #+#             */
/*   Updated: 2024/07/17 14:55:51 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	juliaset(t_fractal *julia)
{
	int			i;
	t_complex	z0;
	t_complex	z1;

	julia->x = 0;
	while (++julia->x <= julia->width)
	{
		julia->y = 0;
		while (++julia->y <= julia->height)
		{
			z0 = mappoint(julia, julia->x, julia->y);
			i = 1;
			while (i++ <= julia->iterations)
			{
				z1 = add(sqr(z0), julia->c);
				if (z1.x * z1.x + z1.y * z1.y > julia->radius * julia->radius)
				{
					my_mlx_pixel_put(julia, julia->x,
						julia->y, julia->color * i);
					break ;
				}
				z0 = z1;
			}
		}
	}
}
