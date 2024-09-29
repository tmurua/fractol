/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:01:31 by tmurua            #+#    #+#             */
/*   Updated: 2024/09/29 22:47:04 by tmurua           ###   ########.fr       */
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
# define MIN_REAL_AXIS -2.0
# define MAX_REAL_AXIS 2.0
# define MIN_IMAGIN_AXIS -1.5
# define MAX_IMAGIN_AXIS 1.5
# define DEFAULT_ZOOM_LEVEL 1.0
# define MAX_ITERATIONS 150
# define PINK 0xff00ff
# define BLACK 0x000000

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

typedef struct s_complex_nbr
{
	double	real;
	double	imagin;
}	t_complex_nbr;

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
	char				*name;
	t_window_init		window_init;
	t_event_handler		event_handler;
}	t_fractol;

/* function prototypes */
/* main.c */
void			wrong_input(void);

/* window_init.c */
void			window_init(t_fractol *fractol);
int				close_window(t_fractol *fractol);

/* fractal_render.c */
void			render_fractal(t_fractol *fractol);
t_complex_nbr	scale_pxl_to_complex(int pxl_x, int pxl_y);
int				calculate_color(int iterations);
void			put_pxl_color_to_img(t_fractol *f, int x, int y, int color);

/* mandelbrot_set.c */
int				mandelbrot_iteration(t_complex_nbr c);
void			render_mandelbrot(t_fractol *fractol);

/* julia_sets.c */
//void    render_julia(t_fractol *fractol);

/* burning_set.c */
//void    render_burning_ship(t_fractol *fractol);

#endif
