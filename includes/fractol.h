/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:07:26 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 17:19:22 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../mylib/ft_print/ft_printf.h"

# define ESCAPE_COUNT 100
# define WIDTH 720
# define HEIGHT 720
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define MAGENTA	0xFF00FFFF
# define CYAN	0x00FFFFFF
# define YELLOW	0xFFFF00FF
# define ORANGE	0xFFA500FF
# define PURPLE	0x800080FF
# define PINK	0xFFC0CBFF
# define LIME	0x32CD32FF
# define DEEP	0xFF1493FF
# define GREEN	0x00FF00FF
# define VIOLET	0x8A2BE2FF
# define ORANGER	0xFF4500FF
# define TOMATO	0xFF6347FF
# define AQUA	0x00FFFFFF
# define TEAL	0x008080FF
# define GOLD	0xFFD700FF
# define SILVER	0xC0C0C0FF
# define GRAY	0x808080FF
# define BROWN 	0xA52A2AFF

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef enum sets
{
	MANDELBROT,
	JULIA,
	TRICORN,
	MANDELBROT2,
	JULIA2,
	TRICORN2,
}	t_sets;


typedef struct s_fractal
{
	char			*name;
	int				id;
	mlx_image_t		*img;
	void			*mlx;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			xzoom;
	double			yzoom;
	double			zoom_factor;
	t_complex		c;
	double			escape_value;
	double			initial_zoom;
	double			zoom;
	double			x_shift;
	double			y_shift;
	int				mouse_x;
	int				mouse_y;
	unsigned int	iterations;
	unsigned int	color;
	unsigned int	color2;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}				t_fractal;

void			update_render(t_fractal *fractal);
void			fractal_init(t_fractal *fractal, int id, double c_x, double c_y);
void			select_fractal(t_fractal *fractal);


//color
unsigned int	map_color(int iter, t_fractal *fractal);
void			pick_color(t_fractal *fractal);
unsigned int	darken_color(t_fractal *fractal);

void			fractal_init(t_fractal *fractal, int id, double c_x, double c_y);
void			select_fractal(t_fractal *fractal);
void			update_render(t_fractal *fractal);
void			mandelbrot_data_init(t_fractal *fractal);
void			mandelbrot_render(t_fractal *fractal);
void			julia_data_init(t_fractal *fractal, double c_x, double c_y);
void			randomize_julia(t_fractal *fractal_ptr);
void			julia_render(t_fractal *fractal);
void			tricorn_render(t_fractal *fractal);
void			tricorn_data_init(t_fractal *fractal);


void			keyhook(void *param);
void			scrollhook(double xdelta, double ydelta, void	*param);
void			cursorhook(double xmouse, double ymouse, void	*param);
t_complex		complex_sum(t_complex a, t_complex b);
t_complex		complex_sqr(t_complex a);
t_complex		complex_power(t_complex a, int n);
t_complex		complex_conjugate(t_complex a);

void			error(void);
void			param_error(void);
void			guide(void);
double			ft_atod(char *str);

void			julia_render_glitch(t_fractal *fractal);
void			mandelbrot_render_glitch(t_fractal *fractal);
void			tricorn_render_glitch(t_fractal *fractal);
void			julia_data_init_glitch(t_fractal *fractal, double c_x,
					double c_y);
void			mandelbrot_data_init_glitch(t_fractal *fractal);
void			tricorn_data_init_glitch(t_fractal *fractal);


#endif