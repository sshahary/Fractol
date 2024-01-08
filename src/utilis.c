/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:29:38 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/07 15:30:38 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atod(char *str)
{
	long	integer_part;
	double	decimal_part;
	double	decimal_factor;
	int		sign;

	integer_part = 0;
	decimal_part = 0;
	sign = 1;
	decimal_factor = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while ((*str >= '0' && *str <= '9') && *str && *str != '.')
		integer_part = integer_part * 10 + (*str++ - '0');
	if (*str == '.')
		++str;
	while ((*str >= '0' && *str <= '9') && *str)
	{
		decimal_factor /= 10;
		decimal_part += (*str++ - '0') * decimal_factor;
	}
	return ((integer_part + decimal_part) * sign);
}

void	set_screen_size(t_fractol *f)
{
	if (ft_strncmp("J", f->set, 1) == 0)
	{
		f->start_x = -2.0;
		f->end_x = 2.0;
		f->start_y = -2.0;
		f->end_y = 2.0;
	}
	else
	{
		f->start_x = -4.0;
		f->end_x = 4.0;
		f->start_y = -4.0;
		f->end_y = f->start_y + (f->end_x - f->start_x) * HEIGHT / WID;
	}
}

static void	init_cs(t_color *fractol)
{
	fractol->shift = -999;
	fractol->r_set = 0;
	fractol->g_set = 0;
	fractol->b_set = 0;
	fractol->hue = 0;
	fractol->saturation = 0;
	fractol->brightness = 0;
	fractol->contrast = 100;
	fractol->c = 0;
	fractol->x = 0;
	fractol->m = 0;
	fractol->r = 0;
	fractol->g = 0;
	fractol->b = 0;
	fractol->palette = 0;
}

void	init(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->end_y = 0;
	fractol->end_x = 0;
	fractol->start_y = 0;
	fractol->start_x = 0;
	fractol->ci = 0;
	fractol->cr = 0;
	fractol->m_zi = 0;
	fractol->m_zr = 0;
	fractol->err = 0;
	fractol->index = 0;
	fractol->zoom = 1.48;
	set_screen_size(fractol);
	init_cs(&fractol->css);
}
