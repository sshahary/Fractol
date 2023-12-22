/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:46:04 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/11 11:46:05 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					i;
	const unsigned char	*s;

	i = 0;
	s = (unsigned char *)src;
	if (len == 0 || src == ((unsigned char *)dst))
		return ((unsigned char *)dst);
	if (s < (unsigned char *)dst && s + (int)len > (unsigned char *)dst)
	{
		while ((int)len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = s[len];
		}
	}
	else
	{
		while (i < (int)len)
		{
			((unsigned char *)dst)[i] = s[i];
			i++;
		}
	}
	return ((unsigned char *)dst);
}

// (3, dest, dest_std, dest, dest_std, "123456", 4) && res;

// int main(void) {
//     // // Test case 1: Non-overlapping regions
//     // char str1[] = "123456";
//     // char buffer1[6];
//     // size_t len1 = 4; // Include null terminator

//     // ft_memmove(buffer1, str1, len1);

// 	char	src[] = "lorem ipsum dolor sit amet";
// 	char	*dest;
// 	dest = src + 1;

// 	ft_memmove(dest, src, 8);

//     printf("STR %s\n", dest);

//     return 0;
// }