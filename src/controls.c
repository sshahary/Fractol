/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:14:13 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/07 15:55:33 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	exit_mlx(t_img *f)
{
	mlx_delete_image(f->mlx, f->img);
	mlx_close_window(f->mlx);
	mlx_terminate(f->mlx);
	exit(EXIT_SUCCESS);
}

void	keyboard(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		exit_mlx(&fractol->img);
		return ;
	}
	else if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move(fractol, 0.2, 'U');
	else if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move(fractol, 0.2, 'D');
	else if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move(fractol, 0.2, 'L');
	else if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move(fractol, 0.2, 'R');
	else if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		shift_color(&fractol->css);
	else
		return ;
	draw_fractal(fractol);
}

void	zoom(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double	x_math;
	double	y_math;
	double	new_x_range;
	double	new_y_range;

	x_math = fractol->start_x + ((double)x / WID)
		* (fractol->end_x - fractol->start_x);
	y_math = fractol->start_y + (1 - (double)y / HEIGHT)
		* (fractol->end_y - fractol->start_y);
	new_x_range = (fractol->end_x - fractol->start_x) / zoom_factor;
	new_y_range = (fractol->end_y - fractol->start_y) / zoom_factor;
	fractol->start_x = x_math - ((double)x / WID) * new_x_range;
	fractol->end_x = fractol->start_x + new_x_range;
	fractol->start_y = y_math - (1 - (double)y / HEIGHT) * new_y_range;
	fractol->end_y = fractol->start_y + new_y_range;
}

void	move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->end_x - f->start_x;
	center_i = f->end_y - f->start_y;
	if (direction == 'R')
	{
		f->start_x += center_r * distance;
		f->end_x += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->start_x -= center_r * distance;
		f->end_x -= center_r * distance;
	}
	else if (direction == 'U')
	{
		f->start_y += center_i * distance;
		f->end_y += center_i * distance;
	}
	else if (direction == 'D')
	{
		f->start_y -= center_i * distance;
		f->end_y -= center_i * distance;
	}
}

void	mouse(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;

	(void)xdelta;
	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->img.mlx, &mouse_x, &mouse_y);
	if (ydelta < 0)
		zoom(fractol, mouse_x, mouse_y, fractol->zoom);
	else if (ydelta > 0)
		zoom(fractol, mouse_x, mouse_y, 1 / fractol->zoom);
	draw_fractal(fractol);
}
