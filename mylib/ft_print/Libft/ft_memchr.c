/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:48:06 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/11 11:44:59 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*b;

	c = c % 256;
	i = 0;
	b = (unsigned char *)s;
	while (i < (int)n)
	{
		if (b[i] == (unsigned char)c)
			return (b + i);
		i++;
	}
	return (0);
}

// int main() {
//     char str[] = "This is a sample string";
//     int target_char = 's';
//     size_t len = sizeof(str);

//     // Search for the first occurrence of 's' in str
//     void *result = ft_memchr(str, target_char, len);

//     if (result != NULL) {
//  printf("Found%zu\", target_char, (size_t)((char *)result - str));
//     } else {
//         printf("'%c' not found in the string.\n", target_char);
//     }

//     return 0;
// }