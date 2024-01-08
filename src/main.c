/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:19:09 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/07 17:02:22 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_fractol	*f)
{
	mlx_delete_image(f->img.mlx, f->img.img);
	f->img.img = mlx_new_image(f->img.mlx, WID, HEIGHT);
	mlx_image_to_window(f->img.mlx, f->img.img, 0, 0);
	f->x = 0;
	f->y = 0;
	while (f->x < WID)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			f->cr = f->start_x + ((double)f->x * (f->end_x - f->start_x)) / WID;
			f->ci = f->end_y + (double)f->y * (f->start_y - f->end_y) / HEIGHT;
			if (ft_strncmp("M", f->set, 1) == 0)
				f->index = mandelbrot(f);
			else if (ft_strncmp("J", f->set, 1) == 0)
				f->index = julia(f);
			else if (ft_strncmp("T", f->set, 1) == 0)
				f->index = tricorn(f);
			else
				f->err = -1;
			mlx_put_pixel(f->img.img, f->x, f->y, ft_color(f));
			f->y++;
		}
		f->x++;
	}
}

void	pars_args(int ac, char **argv, t_fractol *fractol)
{
	if (ac == 2 && !ft_strncmp("mandelbrot", argv[1], 10))
		fractol->set = "M";
	else if (ac == 2 && !ft_strncmp("julia", argv[1], 5))
	{
		fractol->set = "J";
		fractol->j_ci = -0.090000;
		fractol->j_cr = -0.766667;
	}
	else if (ac == 2 && ! ft_strncmp("tricorn", argv[1], 7))
		fractol->set = "T";
	else if (ac == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (ft_atod(argv[2]) >= -2.0 && ft_atod(argv[2]) <= 2.0
			&& ft_atod(argv[3]) >= -2.0 && ft_atod(argv[3]) <= 2.0)
		{
			fractol->set = "J";
			fractol->j_ci = ft_atod(argv[3]);
			fractol->j_cr = ft_atod(argv[2]);
		}
		else
			fractol->err = -1;
	}
	else
		fractol->err = -1;
}

int	main(int ac, char **argv)
{
	t_fractol	fractol;
	t_img		img;

	img.mlx = mlx_init(WID, HEIGHT, "Fractol", true);
	img.img = mlx_new_image(img.mlx, WID, HEIGHT);
	if (!img.img)
		return (1);
	fractol.img = img;
	pars_args(ac, argv, &fractol);
	if (fractol.err == -1)
	{
		param_error();
		return (EXIT_FAILURE);
	}
	guide();
	init(&fractol);
	draw_fractal(&fractol);
	mlx_scroll_hook(img.mlx, &mouse, &fractol);
	mlx_key_hook(img.mlx, &keyboard, &fractol);
	mlx_loop(fractol.img.mlx);
	mlx_terminate(fractol.img.mlx);
	return (EXIT_SUCCESS);
}
