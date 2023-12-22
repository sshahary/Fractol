/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:07:26 by sshahary          #+#    #+#             */
/*   Updated: 2023/12/22 16:34:41 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../mylib/ft_print/ft_printf.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 1000

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

int	ft_sqrt(unsigned int n);

#endif