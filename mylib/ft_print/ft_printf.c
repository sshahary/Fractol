/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:46:42 by sshahary          #+#    #+#             */
/*   Updated: 2023/11/15 10:39:56 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (s == '%')
		count += ft_putchar('%');
	if (s == 'x')
		count += ft_putnbr_hexa_min(va_arg(args, unsigned int));
	if (s == 'X')
		count += ft_putnbr_hexa(va_arg(args, unsigned int));
	if (s == 'u')
		count += ft_unsigned_num(va_arg(args, unsigned int));
	if (s == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_point_arg(va_arg(args, unsigned long int));
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				count;
	va_list			args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_format(args, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {

// 	//ft_printf(NULL);
// 	printf(NULL);
// }