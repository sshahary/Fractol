/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:37:56 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/17 15:22:27 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_min(unsigned int n)
{
	char	*c;
	int		count;

	count = 0;
	c = "0123456789abcdef";
	if (n == 0)
		count += write(1, "0", 1);
	else if (n < 16)
		count += write(1, &c[n], 1);
	else
	{
		count += ft_putnbr_hexa_min(n / 16);
		count += ft_putnbr_hexa_min(n % 16);
	}
	return (count);
}

int	ft_point_arg(unsigned long int nb)
{
	unsigned int	count;
	char			*c;

	c = "0123456789abcdef";
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count += 1;
	}
	if (nb < 16)
		count += write(1, &c[nb], 1);
	else
	{
		count += ft_point_arg(nb / 16);
		count += ft_point_arg(nb % 16);
	}
	return (count);
}
