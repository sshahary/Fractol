/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:09:36 by sshahary          #+#    #+#             */
/*   Updated: 2023/12/22 16:36:17 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_complex c, t_complex z, int iteration)
{
	t_complex	z_next;

	z_next.real = z.real * z.real - z.imag * z.imag + c.real;
	z_next.imag = 2.0 * z.real * z.imag + c.imag;
	if (iteration == MAX_ITER
		|| ft_sqrt(z.real * z.real + z.imag * z.imag) >= 4.0)
		return (iteration);
	return (mandelbrot(c, z_next, iteration + 1));
}

// void	drawMandelbrot(void)
// {
// 	for (int y = 0; y < HEIGHT; y++) {
// 		for (int x = 0; x < WIDTH; x++)
// 		{
// 			t_complex c, z;
// 			c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
// 			c.imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
// 			z.real = 0;
// 			z.imag = 0;	
// 			int iteration = mandelbrot(c, z, 0);
// 			// Map the iteration count to a color
// 			int r = (iteration % 256);
// 			int g = (iteration % 256);
// 			int b = (iteration % 256);
// 			printf("%3d %3d %3d ", r, g, b);
// 		}
// 		printf("\n");
// 	}
// }

int	main(void)
{
	ft_printf("hey");
}

