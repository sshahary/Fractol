/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:16:02 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/08 07:58:48 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	guide(void)
{
	ft_printf("Controls:\n" \
	"\tpress \033[1m\033[38;5;110mESC\033[0m to exit\n" \
	"\tpress \033[1m\033[38;5;110marrow keys\033[0m to move\n" \
	"\tuse \033[1m\033[38;5;110mmouse scroll\033[0m for zoom\n" \
	"\tpress \033[1m\033[38;5;110mSPACE\033[0m to change color\n");
}

void	param_error(void)
{
	ft_printf("\n\nError - incorrect params\n\n" \
"params:\t \033[1m\033[38;5;110mmandelbrot\n" \
"\t \033[1m\033[38;5;110mtricorn\n" \
"\t julia \033[0m\033[38;5;115m<real> <imaginary>\033[0m\n\n" \
"examples:\n" \
"./fractol julia \033[38;5;115m0.285 0.01\033[0m\n" \
"./fractol julia \033[38;5;115m-0.8 0.156\n");
}

static void	reset(t_color *cs)
{
	cs->contrast = 100;
	cs->shift = -999;
	cs->palette = 0;
}

int	shift_color(t_color *cs)
{
	if (cs->palette == 0)
	{
		cs->contrast = 80;
		cs->shift = 60;
	}
	else if (cs->palette == 1)
	{
		cs->contrast = 40;
		cs->shift = 180;
	}
	else if (cs->palette == 2)
	{
		cs->contrast = 100;
		cs->shift = 260;
	}
	else if (cs->palette == 3)
	{
		cs->contrast = 70;
		cs->shift = 360;
	}
	else
		reset(cs);
	cs->palette++;
	return (0);
}
