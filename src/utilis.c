/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:49:36 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 17:18:16 by sshahary         ###   ########.fr       */
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

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	guide(void)
{
	puts("Controls:\n" \
	"\tpress \033[1m\033[38;5;110mESC\033[0m to exit\n" \
	"\tpress \033[1m\033[38;5;110marrow keys\033[0m to move\n" \
	"\tuse \033[1m\033[38;5;110mmouse scroll\033[0m for zoom\n" \
	"\tpress \033[1m\033[38;5;110mTAB\033[0m to change fractal\n" \
	"\tpress \033[1m\033[38;5;110mC\033[0m to change color\n" \
	"\t keep \033[1m\033[38;5;110mG\033[0m pressed for glitchy colors\n" \
	"\nJulia Set constants:\n" \
	"\tpress \033[1m\033[38;5;110mR\033[0m to randomize \n"\
	"\tuse \033[1m\033[38;5;110mleft_shift + scroll\033[0m " \
	"to increase or decrease\n" \
	"\tuse \033[1m\033[38;5;110mleft_ctrl + mouse \033[0m"\
	"to change constants based on relative mouse position\n");
}

void	param_error(void)
{
	puts("\n\nError - incorrect params\n\n" \
"params:\t \033[1m\033[38;5;110mmandelbrot\n" \
"\t \033[1m\033[38;5;110mtricorn\n" \
"\t julia \033[0m\033[38;5;115m<real> <imaginary>\033[0m\n\n" \
"examples:\n" \
"./fractol julia \033[38;5;115m0.285 0.01\033[0m\n" \
"./fractol julia \033[38;5;115m-0.8 0.156\n");
}
