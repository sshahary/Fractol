/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliaglitch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:04:32 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 17:05:22 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_data_init_glitch(t_fractal *fractal, double c_x, double c_y)
{
	fractal->name = "❄️ Julia 2 ❄️";
	fractal->id = JULIA2;
	fractal->color = CYAN;
	fractal->escape_value = 4.0;
	fractal->iterations = ESCAPE_COUNT;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
	fractal->initial_zoom = 1;
	fractal->zoom = 1.0;
	fractal->c.real = c_x;
	fractal->c.i = c_y;
	fractal->xmin = -2.0 * fractal->initial_zoom;
	fractal->xmax = 2.0 * fractal->initial_zoom;
	fractal->ymin = -2.0 * fractal->initial_zoom;
	fractal->ymax = 2.0 * fractal->initial_zoom;
}

void	handle_julia_pixel_glitch(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	unsigned int	i;

	i = 0;
	z.real = ((x - 0) * (fractal->xmax - fractal->xmin))
		/ (WIDTH - 0) + fractal->xmin + fractal->x_shift;
	z.i = ((y - 0) * (fractal->ymax - fractal->ymin))
		/ (HEIGHT - 0) + fractal->ymin + fractal->y_shift;
	while (i < fractal->iterations)
	{
		z = complex_sum(complex_sqr(z), fractal->c);
		if ((((z.real * z.real) + (z.i * z.i)) < fractal->escape_value))
			mlx_put_pixel(fractal->img, x, y, fractal->color * 0.9995);
		else if ((z.real * z.real + z.i * z.i) > fractal->escape_value)
		{
			fractal->color2 = map_color(i, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color2);
			return ;
		}
		i++;
	}
}

void	randomize_julia_glitch(t_fractal *fractal_ptr)
{
	fractal_ptr->c.real = (drand48() * 1.2) - 0.8;
	fractal_ptr->c.i = (drand48() * 1.4) - 0.7;
}

void	julia_render_glitch(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_julia_pixel_glitch(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
