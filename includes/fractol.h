/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:12:42 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/08 07:59:52 by sshahary         ###   ########.fr       */
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

# ifndef WID
#  define WID 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

typedef struct s_img
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_img;

typedef struct s_color
{
	int	shift;
	int	r_set;
	int	g_set;
	int	b_set;
	int	hue;
	int	saturation;
	int	brightness;
	int	contrast;
	int	c;
	int	x;
	int	m;
	int	r;
	int	g;
	int	b;
	int	palette;
}	t_color;

typedef struct s_fractol
{
	char			*set;
	t_img			img;
	int				index;
	int				x;
	int				y;
	int				err;
	double			j_cr;
	double			j_ci;
	double			m_zi;
	double			m_zr;
	double			start_x;
	double			start_y;
	double			end_x;
	double			end_y;
	double			ci;
	double			cr;
	double			zoom;
	t_color			css;
}	t_fractol;

double			ft_atod(char *str);
int				mandelbrot(t_fractol *f);
int				julia(t_fractol *f);
int				tricorn(t_fractol *f);
void			draw_fractal(t_fractol	*f);
void			set_screen_size(t_fractol *f);
void			init(t_fractol *fractol);
int				ft_color(t_fractol *f);
int				shift_color(t_color *cs);
void			keyboard(mlx_key_data_t key, void *param);
void			mouse(double xdelta, double ydelta, void *param);
void			zoom(t_fractol *fractol, int x, int y, double zoom_factor);
void			move(t_fractol *f, double distance, char direction);
int				shift_color(t_color *cs);
void			guide(void);
void			param_error(void);

#endif