/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:01:43 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 17:02:22 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void	pick_color(t_fractal *fractal)
{
	if (fractal->color == CYAN)
		fractal->color = GOLD;
	else if (fractal->color == GOLD)
		fractal->color = TOMATO;
	else if (fractal->color == TOMATO)
		fractal->color = PINK;
	else if (fractal->color == PINK)
		fractal->color = ORANGER;
	else if (fractal->color == ORANGER)
		fractal->color = VIOLET;
	else if (fractal->color == VIOLET)
		fractal->color = TEAL;
	else if (fractal->color == TEAL)
		fractal->color = BROWN;
	else if (fractal->color == BROWN)
		fractal->color = MAGENTA;
	else if (fractal->color == MAGENTA)
		fractal->color = YELLOW;
	else
		fractal->color = CYAN;
}

unsigned int	darken_color(t_fractal *fractal)
{
	fractal->r = (fractal->color >> 24 & 0xFF) * 0.100;
	fractal->g = (fractal->color >> 16 & 0xFF) * 0.100;
	fractal->b = (fractal->color >> 8 & 0xFF) * 0.100;
	return ((fractal->r << 24) | (fractal->g << 16) | (fractal->b << 8) | 255);
}

unsigned int	map_color(int iter, t_fractal *fractal)
{
	double	interpolation_factor;
	double	smoothed_factor;

	fractal->r = fractal->color >> 24 & 0xFF;
	fractal->g = fractal->color >> 16 & 0xFF;
	fractal->b = fractal->color >> 8 & 0xFF;
	interpolation_factor = (double)iter / (double)fractal->iterations;
	smoothed_factor = pow(interpolation_factor, 0.9);
	if ((interpolation_factor < smoothed_factor * 5))
	{
		fractal->r *= smoothed_factor;
		fractal->g *= smoothed_factor;
		fractal->b *= smoothed_factor;
	}
	else
	{
		if (mlx_is_key_down(fractal->mlx, MLX_KEY_G))
			pick_color(fractal);
		fractal->r *= ((smoothed_factor) * 0.9);
		fractal->g *= ((smoothed_factor) * 0.9);
		fractal->b *= ((smoothed_factor) * 0.9);
	}
	return ((fractal->r << 24) | (fractal->g << 16) | (fractal->b << 8) | 255);
}
