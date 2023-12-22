/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:07:48 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/17 15:44:20 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		count += 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
			count++;
		}
	}
	return (count);
}

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		count += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
		count += ft_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		c = '0' + n;
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_unsigned_num(unsigned int n)
{
	unsigned int	count;
	char			c;

	count = 0;
	if (n > 9)
	{
		count += ft_unsigned_num(n / 10);
		count += ft_unsigned_num(n % 10);
	}
	else
	{
		c = '0' + n;
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_putnbr_hexa(unsigned int n)
{
	char	*c;
	int		count;

	count = 0;
	c = "0123456789ABCDEF";
	if (n == 0)
		count += write(1, "0", 1);
	else if (n < 16)
		count += write(1, &c[n], 1);
	else
	{
		count += ft_putnbr_hexa(n / 16);
		count += ft_putnbr_hexa(n % 16);
	}
	return (count);
}
