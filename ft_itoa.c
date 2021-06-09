/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:29:03 by abensett          #+#    #+#             */
/*   Updated: 2021/06/09 15:29:05 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n1)
{
	char	*s;
	long	n;
	
	n = n1;
	s = (char *) malloc(sizeof (char) * 2);
	if (s == NULL)
		return (NULL);

	if (n < 0)
	{
		s[0] = '-';
		s[1] = '\0';
		s = ft_strjoin(s, ft_itoa(-n));
	}
	else if (n > 9)
		s = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n <= 9 && n >= 0)
	{
		s[0] = n + '0';
		s[1] = '\0';
	}
	return (s);
}
