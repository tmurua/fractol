/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:01:31 by tmurua            #+#    #+#             */
/*   Updated: 2024/10/02 17:55:59 by tmurua           ###   ########.fr       */
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
# define MAX_ITERATIONS 150
# define PINK 0xff00ff
# define BLACK 0x000000
# define ESC 65307
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define MOVE_REAL_AXIS 0.1
# define MOVE_IMAGIN_AXIS 0.1
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define DEFAULT_ZOOM_LEVEL 1.0

/* stuctures */
typedef struct s_window_init
{
	void	*mlx_init;
	void	*mlx_new_window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		bytes_per_vertical_line;
	int		endian;
}	t_window_init;

typedef struct s_complex_nbr
{
	double	real;
	double	imagin;
}	t_complex_nbr;

typedef struct s_event_handler
{
	double	real_axis;
	double	imagin_axis;
	double	scale_zoom;
}	t_event_handler;

typedef struct s_fractol
{
	char				*name;
	t_window_init		window_init;
	t_event_handler		event_handler;
	t_complex_nbr		julia_c;
}	t_fractol;

/* function prototypes */
/* main.c */
int				input_arguments(int argc, char **argv, t_fractol*fractol);
void			fractol_init(t_fractol *fractol);
void			wrong_input(void);

/* window_init.c */
void			window_init(t_fractol *fractol);
void			create_image_buffer(t_fractol *fractol);
int				close_window(t_fractol *fractol);

/* fractal_render.c */
void			render_fractal(t_fractol *fractol);
void			process_pixel(int pxl_x, int pxl_y, t_fractol *fractol);
t_complex_nbr	scale_pxl_to_complex(int pxl_x, int pxl_y, t_fractol *fractol);
int				calculate_color(int iterations);
void			put_pxl_color_to_img(t_fractol *f, int x, int y, int color);

/* iterative_equations.c */
t_complex_nbr	polynomial_quadratic_i(t_complex_nbr z, t_complex_nbr c);
t_complex_nbr	square_complex_number(t_complex_nbr z);
int				mandelbrot_iteration(t_complex_nbr c);
int				julia_iteration(t_complex_nbr z, t_fractol *fractol);

/* event_handler.c */
void			events_handler(t_fractol *fractol);
int				press_keys_handler(int keycode, t_fractol *fractol);
int				mouse_handler(int wheel, int x, int y, t_fractol *fractol);
void			adjust_zoom(int wheel, t_fractol *fractol);
void			adjust_center_position(int x, int y, t_fractol *fractol);

/* ft_atof.c */
double			ft_atof(const char *str);
int				handle_sign(const char *str, int *i);

#endif
