/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:12:58 by sshahary          #+#    #+#             */
/*   Updated: 2023/10/13 09:49:32 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;
	size_t	max;

	max = 0 - 1;
	if ((long long)count * size > max)
		return (NULL);
	i = 0;
	s = (char *)malloc(count * size);
	if (!s)
		return (NULL);
	while (count * size > i)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
