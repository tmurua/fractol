/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:01:31 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/26 23:52:12 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/* macros */
# define WIDTH 800
# define HEIGHT 600

/* stuctures */
typedef struct s_window_init
{
	void	*mlx_init;
	void	*mlx_new_window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_window_init;

typedef struct s_fractal_render
{
	char	*name;
	double	min_real;
	double	max_real;
	double	min_imagin;
	double	max_imagin;
	double	zoom_level;
	double	iterations;
	//julia_c_real;
	//julia_c_i;
	//color;
}	t_fractal_render;

typedef struct s_event_handler
{
	double	mouse_x;
	double	mouse_y;
	//arrow_x
	//arrow_y
	//window_close
}	t_event_handler;

typedef struct s_fractol
{
	t_window_init		window_init;
	t_fractal_render	fractal_render;
	t_event_handler		event_handler;
}	t_fractol;




/* function prototypes */
/* main.c */
void	wrong_input(void);

/* window_init.c */
void	window_init(t_fractol *fractol);
int		close_window(t_fractol *fractol);

/* fractal_render.c */
void	map_coords_to_plane(t_fractol *fractol);

#endif
