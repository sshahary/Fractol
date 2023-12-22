/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:29:28 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/12 17:37:53 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	if ((s[0] == '\0' || start >= ft_strlen(s) || len == 0))
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = -1;
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	while (++i < (int) len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

// void	leak(void)
// {
// 	system("leaks a.out");
// }
// int	main(void)
// {
// 	printf("%s\n", ft_substr("NULL", 10, 10));
// 	// leak();
// 	return (0);
// }
