/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:09:36 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 16:27:39 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static bool	check_input(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && !strncmp(argv[1], "mandelbrot", 10))
		fractal_init(fractal, MANDELBROT, 0, 0);
	else if (argc == 4 && !strncmp(argv[1], "julia", 5))
	{
		if (ft_atod(argv[2]) >= -2.0 && ft_atod(argv[2]) <= 2.0
			&& ft_atod(argv[3]) >= -2.0 && ft_atod(argv[3]) <= 2.0)
			fractal_init(fractal, JULIA, ft_atod(argv[2]), ft_atod(argv[3]));
		else
			return (false);
	}
	else if (argc == 2 && !strncmp(argv[1], "tricorn", 7))
		fractal_init(fractal, TRICORN, 0, 0);
	else
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_fractal		fractal;

	if (check_input(argc, argv, &fractal))
	{
		update_render(&fractal);
		mlx_loop_hook(fractal.mlx, keyhook, &fractal);
		mlx_scroll_hook(fractal.mlx, &scrollhook, &fractal);
		mlx_cursor_hook(fractal.mlx, &cursorhook, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		param_error();
		return (EXIT_FAILURE);
	}
	mlx_delete_image(fractal.mlx, fractal.img);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
