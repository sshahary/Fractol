/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:07:26 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 16:31:29 by sshahary         ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 100

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

void	update_render(t_fractal *fractal);
void	fractal_init(t_fractal *fractal, int id, double c_x, double c_y);
void	select_fractal(t_fractal *fractal);


#endif