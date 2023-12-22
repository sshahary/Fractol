/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:49:36 by sshahary          #+#    #+#             */
/*   Updated: 2023/12/22 14:49:33 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *str)
{
	int		i;
	int		s;
	double	r;
	double	d;

	i = 0;
	s = 1;
	r = 0.0;
	d = 0.1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		s = -s;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && str[i] != '.')
		r = r * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		r = r + (str[i++] - '0') * d;
		d *= 0.1;
	}
	return (r * s);
}

// int	main()
// {
// 	char	str[] = "   -123.45";
// 	float	result = ft_atof(str);

// 	printf("Result: %f\n", result);
// 	return (0);
// }

int	ft_sqrt(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i * i < n)
		i++;
	return (i);
}
