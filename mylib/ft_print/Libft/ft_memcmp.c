/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:25:56 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/11 11:45:22 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	const unsigned char	*b;

	i = 0;
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

// int main() {
//     // Test case 1: Empty strings
//     char empty1[] = "";
//     char empty2[] = "";
//     size_t len1 = 0;
//     //int result1 = ft_memcmp(empty1, empty2, len1);
//     int result1 = memcmp(empty1, empty2, len1);
//     printf("Test 1: Empty strings: Result = %d\n", result1);

//     // Test case 2: Same strings
//     char str1[] = "Hello, World!";
//     char str2[] = "Hello, World!";
//     size_t len2 = strlen(str1);
//     //int result2 = ft_memcmp(str1, str2, len2);
//     int result2 = memcmp(str1, str2, len2);
//     printf("Test 2: Same strings: Result = %d\n", result2);

//     // Test case 3: Different strings
//     char str3a[] = "Hello, World!";
//     char str3b[] = "Hello, Universe!";
//     size_t len3 = strlen(str3a);
//     //int result3 = ft_memcmp(str3a, str3b, len3);
//     int result3 = memcmp(str3a, str3b, len3);
//     printf("Test 3: Different strings: Result = %d\n", result3);

//     // Test case 4: Partial comparison
//     char str4a[] = "Hello, World!";
//     char str4b[] = "Hello, Universe!";
//     size_t len4 = 7; // Compare only the first 7 characters
//     //int result4 = ft_memcmp(str4a, str4b, len4);
//     int result4 = memcmp(str4a, str4b, len4);
//     printf("Test 4: Partial comparison: Result = %d\n", result4);

//     return 0;
// }