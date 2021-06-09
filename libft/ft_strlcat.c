/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:27:31 by abensett          #+#    #+#             */
/*   Updated: 2021/06/09 15:27:59 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	s;
	unsigned int	sizedest;
	unsigned int	sizesrc;

	sizedest = 0;
	sizesrc = 0;
	i = -1;
	s = 0;
	while (src[s++])
		sizesrc++;
	s = -1;
	while (dest[++s])
		sizedest++;
	if (size == 0)
		return (sizesrc + size);
	while (s < size - 1 && src[++i])
		dest[s++] = src[i];
	dest[s] = '\0';
	if (size < sizedest)
		return (sizesrc + size);
	return (sizedest + sizesrc);
}
