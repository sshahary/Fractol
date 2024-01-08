/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:55:34 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/08 08:00:51 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int	absolute(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

static int	set_rgb_upper(t_color *cs)
{
	if (cs->hue < 60)
	{
		cs->r = cs->c;
		cs->g = cs->x;
		cs->b = 0;
		return (1);
	}
	else if (cs->hue < 120)
	{
		cs->r = cs->x;
		cs->g = cs->c;
		cs->b = 0;
		return (1);
	}
	else if (cs->hue < 180)
	{
		cs->r = 0;
		cs->g = cs->c;
		cs->b = cs->x;
		return (1);
	}
	return (0);
}

static void	set_rgb(t_color *cs)
{
	if (set_rgb_upper(cs))
		return ;
	else if (cs->hue < 240)
	{
		cs->r = 0;
		cs->g = cs->x;
		cs->b = cs->c;
	}
	else if (cs->hue < 300)
	{
		cs->r = cs->x;
		cs->g = 0;
		cs->b = cs->c;
	}
	else
	{
		cs->r = cs->c;
		cs->g = 0;
		cs->b = cs->x;
	}
}

int	ft_color(t_fractol *f)
{
	if (f->index == MAX_ITER)
		return (get_rgba(0, 0, 0, 255));
	f->css.hue = (f->index * 360) / f->css.contrast + f->css.shift * 4;
	f->css.saturation = (f->index * 255) / f->css.contrast;
	f->css.brightness = (f->index * 255) / f->css.contrast;
	f->css.c = (255 - absolute(2 * f->css.brightness - 255)) * \
	f->css.saturation / 255;
	f->css.x = f->css.c * (1 - absolute((f->css.hue / 60) % 2 - 1));
	f->css.m = f->css.brightness - f->css.c / 2;
	set_rgb(&f->css);
	return (get_rgba(f->css.r + f->css.m, f->css.g + f->css.m, f->css.b + \
	f->css.m, 255));
}
