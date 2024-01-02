/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:36:13 by sshahary          #+#    #+#             */
/*   Updated: 2024/01/02 16:37:44 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	complex_sum(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.i = a.i + b.i;
	return (c);
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	c;

	c.real = a.real * a.real - a.i * a.i;
	c.i = 2 * a.real * a.i;
	return (c);
}

t_complex	complex_conjugate(t_complex a)
{
	t_complex	c;

	c.real = a.real;
	c.i = -a.i;
	return (c);
}

t_complex	complex_power(t_complex a, int exponent)
{
	t_complex	result;
	t_complex	temp;
	int			i;

	result.real = 1.0;
	result.i = 0.0;
	i = 0;
	while (i < exponent)
	{
		temp = result;
		result.real = temp.real * a.real - temp.i * a.i;
		result.i = temp.real * a.i + temp.i * a.real;
		i++;
	}
	return (result);
}
