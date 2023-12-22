/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:09:36 by sshahary          #+#    #+#             */
/*   Updated: 2023/12/22 17:54:14 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_complex c, t_complex z, int iteration)
{
	t_complex	z_next;

	if (iteration == MAX_ITER
		|| ft_sqrt(z.real * z.real + z.imag * z.imag) > 4.0)
		return (iteration);
	z_next.real = z.real * z.real - z.imag * z.imag + c.real;
	z_next.imag = 2.0 * z.real * z.imag + c.imag;
	return (mandelbrot(c, z_next, iteration + 1));
}

void	draw_mandelbrot(mlx_image_t *img)
{
	int			x;
	int			y;
	t_complex	c;
	t_complex	z;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = (x - WIDTH / 2.0) / (WIDTH / 4.0);
			c.imag = (y - HEIGHT / 2.0) / (HEIGHT / 4.0);
			z.real = 0;
			z.imag = 0;
			color = mandelbrot(c, z, 0) * 255 / MAX_ITER;
			// Assuming 32-bit pixels with an alpha channel
			uint32_t pixel_offset = (y * img->width + x);
			img->pixels[pixel_offset * 4] = color;
			img->pixels[pixel_offset * 4 + 1] = color;
			img->pixels[pixel_offset * 4 + 2] = color;
			img->pixels[pixel_offset * 4 + 3] = 255; // Alpha channel
			x++;
		}
		y++;
	}
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!mlx)
	{
		ft_printf("Error: Failed to initialize mlx.\n");
		return (1);
	}
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
	{
		ft_printf("Error: Failed to create image.\n");
		return (1);
	}

	draw_mandelbrot(img);

	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_printf("ERROR");
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (0);
}


