/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:28:46 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 16:55:29 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	select_fractal(t_fractal *fractal)
{
	if (fractal->id == MANDELBROT)
	{
		fractal->c.real = (drand48() * 1.2) - 0.8;
		fractal->c.i = (drand48() * 1.4) - 0.7;
		julia_data_init(fractal, fractal->c.real, fractal->c.i);
	}
	else if (fractal->id == JULIA)
		tricorn_data_init(fractal);
	else if (fractal->id == TRICORN)
		mandelbrot_data_init_glitch(fractal);
	else if (fractal->id == MANDELBROT2)
	{
		fractal->c.real = (drand48() * 1.2) - 0.8;
		fractal->c.i = (drand48() * 1.4) - 0.7;
		julia_data_init(fractal, fractal->c.real, fractal->c.i);
	}
	else if (fractal->id == JULIA2)
		tricorn_data_init_glitch(fractal);
	else
		mandelbrot_data_init(fractal);
	mlx_set_window_title(fractal->mlx, fractal->name);
}

void	fractal_init(t_fractal *fractal, int id, double c_x, double c_y)
{
	if (id == MANDELBROT)
		mandelbrot_data_init(fractal);
	if (id == JULIA)
		julia_data_init(fractal, c_x, c_y);
	if (id == TRICORN)
		tricorn_data_init(fractal);
	guide();
	fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx);
		exit(EXIT_FAILURE);
	}
}

void	update_render(t_fractal *fractal)
{
	if (fractal->id == MANDELBROT)
	{
		mandelbrot_render(fractal);
	}
	if (fractal->id == JULIA)
	{
		julia_render(fractal);
	}
	if (fractal->id == TRICORN)
	{
		tricorn_render(fractal);
	}
	if (fractal->id == MANDELBROT2)
	{
		mandelbrot_render_glitch(fractal);
	}
	if (fractal->id == JULIA2)
	{
		julia_render_glitch(fractal);
	}
	if (fractal->id == TRICORN2)
	{
		tricorn_render_glitch(fractal);
	}
}
