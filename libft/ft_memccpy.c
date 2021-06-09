/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:30:12 by abensett          #+#    #+#             */
/*   Updated: 2021/06/09 15:27:05 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		len;
	char		*dest;
	char		*sourc;

	len = 0;
	dest = dst;
	sourc = (char *)src;
	while (len < n && (len == 0 || sourc[len - 1] != c))
	{
		dest[len] = sourc[len];
		len++;
	}
	if (len > 0 && sourc[len - 1] == c)
		return (dest + len);
	else
		return (NULL);
}
