/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:40:55 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 16:44:20 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_data_init(t_fractal *fractal)
{
	fractal->name = "❄️ Mandelbrot ❄️";
	fractal->color = BROWN;
	fractal->id = MANDELBROT;
	fractal->escape_value = 4.0;
	fractal->iterations = ESCAPE_COUNT;
	fractal->x_shift = -0.7;
	fractal->y_shift = 0.0;
	fractal->initial_zoom = 0.7;
	fractal->zoom = 1.0;
	fractal->xmin = -2.0 * fractal->initial_zoom;
	fractal->xmax = 2.0 * fractal->initial_zoom;
	fractal->ymin = -2.0 * fractal->initial_zoom;
	fractal->ymax = 2.0 * fractal->initial_zoom;
}

void	handle_mandelbrot_pixel(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	t_complex		c;
	unsigned int	i;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	c.real = ((fractal->xmax - fractal->xmin) * (x - 0))
		/ (WIDTH - 0) + fractal->xmin + fractal->x_shift;
	c.i = ((fractal->ymax - fractal->ymin) * (y - 0))
		/ (HEIGHT - 0) + fractal->ymin + fractal->y_shift;
	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqr(z), c);
		if ((((z.real * z.real) + (z.i * z.i)) < fractal->escape_value))
			mlx_put_pixel(fractal->img, x, y, darken_color(fractal));
		else if ((z.real * z.real + z.i * z.i) > fractal->escape_value)
		{
			fractal->color2 = map_color(i, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color2);
			return ;
		}
		i++;
	}
}

void	mandelbrot_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_mandelbrot_pixel(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
