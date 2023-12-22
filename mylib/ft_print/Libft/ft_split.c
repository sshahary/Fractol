/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:37:00 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/18 18:03:57 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s && s[k] != '\0')
	{
		if (s[k] == c)
		{
			if (j)
				j = 0;
		}
		else
		{
			if (!j)
			{
				i++;
				j = 1;
			}
		}
		k++;
	}
	return (i);
}

static void	ft_free(char	**str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

static void	fill_ints(size_t *ints)
{
	ints[0] = 0;
	ints[1] = 0;
	ints[2] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	ints[3];

	fill_ints(ints);
	if (!s)
		return (NULL);
	str = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s && s[ints[2]] != '\0' && count_words(s, c))
	{
		while (s[ints[2]] && s[ints[2]] == c)
			ints[2]++;
		ints[0] = ints[2];
		while (s[ints[2]] && s[ints[2]] != c)
			ints[2]++;
		str[ints[1]] = ft_substr(s, ints[0], ints[2] - ints[0]);
		if (!str[ints[1]++])
			return (ft_free(str), NULL);
		while (s[ints[2]] && s[ints[2]] == c)
			ints[2]++;
	}
	str[count_words(s, c)] = NULL;
	return (str);
}

// void	leak(void)
// {
// 	system("leaks a.out");
// }

// int	main(void)
// {
// 	char	**strings = ft_split("this is test", ' ');

// 	for (int i = 0; strings[i]; i++)
// 	{
// 		printf("%s\n", strings[i]);
// 	}
// 	//leak();
// 	return (0);
// }