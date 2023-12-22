/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:12:35 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/12 16:11:02 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = c % 256;
	while (s && s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

// int	main(void)
// {
//printf("\n %s = %s\n", ft_strchr("cdh", '\0'), strchr("cdh", '\0'));
//printf("\n %s = %s\n", ft_strchr("test", 's'), strchr("test", 's'));
// }