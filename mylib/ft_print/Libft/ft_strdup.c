/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:48 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/12 16:31:24 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	int		i;
	int		len;
	char	*a;

	a = (char *) s1;
	i = 0;
	len = 0;
	while (a[len] != '\0')
		len++;
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	while (a[i] != '\0')
	{
		s[i] = a[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

// void	leak(void)
// {
// 	system("leaks a.out");
// }
// int	main(void)
// {
// 	//strdup(NULL);
// 	ft_strdup(NULL);
// 	leak();
// 	return (0);
// }