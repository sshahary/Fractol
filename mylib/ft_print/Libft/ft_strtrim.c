/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:36:57 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/12 17:14:12 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]) != NULL)
		j--;
	str = (char *)malloc(((j - i) + 1));
	if (!str)
		return (str);
	k = 0;
	while (i < j)
	{
		str[k] = s1[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}

// int main() {
//     // Input string and set
//     const char *input = "   Hello, World!   ";
//     const char *set = " ";

//     // Call the ft_strtrim function
//     char *trimmed = ft_strtrim(input, set);

//     if (trimmed) {
//         // Display the trimmed string
//         printf("Trimmed String: \"%s\"\n", trimmed);

//         // Don't forget to free the allocated memory when you're done with it
//         free(trimmed);
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }