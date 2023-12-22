/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:42:21 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/12 16:05:43 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*min_num(char *str)
{
	char	*min;
	int		i;

	i = 0;
	min = "-2147483648";
	while (min[i] != '\0')
	{
		str[i] = min[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	convert_int_to_str(int n, char *str, size_t len)
{
	int	ng;
	int	i;

	i = len - 1;
	if (n == -2147483648)
	{
		min_num(str);
	}
	if (n < 0)
	{
		ng = 1;
		n = -n;
	}
	while (n > 0)
	{
		str[i] = (char)((n % 10) + '0');
		n /= 10;
		i--;
	}
	if (ng == 1)
		str[0] = '-';
	str[len] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_numlen(n);
	if (n == 0)
	{
		str = (char *)malloc((2));
		if (!str)
			return (str);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc(i + 1);
	if (!str)
		return (str);
	convert_int_to_str(n, str, i);
	return (str);
}

// void	leak(void)
// {
// 	system("leaks a.out");
// }

// int	main(void)
// {
// 	ft_itoa(-1);
// 	leak();
// 	return (0);
// }