/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:00:28 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/07 17:01:37 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	f->m_zi = 0;
	f->m_zr = 0;
	while (n < MAX_ITER)
	{
		if ((f->m_zr * f->m_zr + f->m_zi * f->m_zi) > 4.0)
			break ;
		temp = 2 * f->m_zr * f->m_zi + f->ci;
		f->m_zr = f->m_zr * f->m_zr - f->m_zi * f->m_zi + f->cr;
		f->m_zi = temp;
		n++;
	}
	return (n);
}

int	julia(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	while (n < MAX_ITER)
	{
		if ((f->ci * f->ci + f->cr * f->cr) > 4.0)
			break ;
		temp = 2 * f->cr * f->ci + f->j_ci;
		f->cr = f->cr * f->cr - f->ci * f->ci + f->j_cr;
		f->ci = temp;
		n++;
	}
	return (n);
}

int	tricorn(t_fractol *f)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = f->cr;
	zi = f->ci;
	n = 0;
	while (n < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + f->ci;
		zr = zr * zr - zi * zi + f->cr;
		zi = tmp;
		n++;
	}
	return (n);
}
