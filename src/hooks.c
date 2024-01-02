/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:57:28 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 16:59:07 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	arrows_keys(t_fractal *fractal)
{
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
	{
		fractal->y_shift -= 0.1 * fractal->zoom;
		update_render(fractal);
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
	{
		fractal->y_shift += 0.1 * fractal->zoom;
		update_render(fractal);
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
	{
		fractal->x_shift -= 0.1 * fractal->zoom;
		update_render(fractal);
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
	{
		fractal->x_shift += 0.1 * fractal->zoom;
		update_render(fractal);
	}
}

void	keyhook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	arrows_keys(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fractal->mlx);
	}
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_C))
	{
		pick_color(fractal);
		update_render(fractal);
	}
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_R))
	{
		randomize_julia(fractal);
		update_render(fractal);
	}
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_TAB))
	{
		select_fractal(fractal);
		update_render(fractal);
	}
	else if (mlx_is_key_down(fractal->mlx, MLX_KEY_G))
		update_render(fractal);
}

void	zoom(double ydelta, t_fractal *fr)
{
	double		zoom_factor;

	zoom_factor = 1.1;
	if (ydelta > 0)
	{
		fr->zoom *= 0.9;
		fr->xmin = fr->xzoom - (1.0 / zoom_factor) * (fr->xzoom - fr->xmin);
		fr->xmax = fr->xzoom + (1.0 / zoom_factor) * (fr->xmax - fr->xzoom);
		fr->ymin = fr->yzoom - (1.0 / zoom_factor) * (fr->yzoom - fr->ymin);
		fr->ymax = fr->yzoom + (1.0 / zoom_factor) * (fr->ymax - fr->yzoom);
	}
	else if (ydelta < 0)
	{
		fr->zoom *= 1.1;
		fr->xmin = fr->xzoom - zoom_factor * (fr->xzoom - fr->xmin);
		fr->xmax = fr->xzoom + zoom_factor * (fr->xmax - fr->xzoom);
		fr->ymin = fr->yzoom - zoom_factor * (fr->yzoom - fr->ymin);
		fr->ymax = fr->yzoom + zoom_factor * (fr->ymax - fr->yzoom);
	}
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	xdelta = 0;
	mlx_get_mouse_pos(fractal->mlx, &fractal->mouse_x, &fractal->mouse_y);
	fractal->xzoom = fractal->xmin + fractal->mouse_x
		* ((fractal->xmax - fractal->xmin) / WIDTH);
	fractal->yzoom = fractal->ymin + fractal->mouse_y
		* ((fractal->ymax - fractal->ymin) / HEIGHT);
	if (fractal->id == JULIA
		&& mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT_SHIFT))
	{
		fractal->c.real += (ydelta / 400) * fractal->zoom;
		fractal->c.i += (ydelta / 400) * fractal->zoom;
		update_render(fractal);
	}
	else if (ydelta != 0)
	{
		zoom(ydelta, fractal);
		update_render(fractal);
	}
}

void	cursorhook(double xmouse, double ymouse, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	xmouse = 0;
	ymouse = 0;
	mlx_get_mouse_pos(fractal->mlx, &fractal->mouse_x,
		&fractal->mouse_y);
	if (fractal->id == JULIA
		&& mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT_CONTROL))
	{
		fractal->c.real = ((fractal->mouse_x) * (fractal->xmax - fractal->xmin)
				* 0.9) / (WIDTH) + (fractal->xmin * 0.9) + fractal->x_shift;
		fractal->c.i = ((fractal->mouse_y) * (fractal->ymax - fractal->ymin)
				* 0.9) / (HEIGHT) + (fractal->ymin * 0.9) + fractal->y_shift;
		update_render(fractal);
	}
}
