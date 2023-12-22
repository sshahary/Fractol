/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:05:32 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/13 11:51:27 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	j = 0;
	r = 0;
	while (dst && dst[i] != '\0')
		i++;
	while (src && src[r] != '\0')
		r++;
	if (dstsize <= i)
		r += dstsize;
	else
		r += i;
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (r);
}

// int	main(void)
// {
// 	ft_strlcat(NULL,"", 2);
// }
