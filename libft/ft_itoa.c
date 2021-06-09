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
int	ft_nblen(int	nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_miitoa( char *s, int i, int leni)
{
	long	j;

	j = 1;
	if (i == -2147483648)
		ft_strlcpy(s, "-2147483648", 12);
	else
	{
		if (i < 0)
		{
			j = -1;
			leni++;
		}
		j = j * i;
		while (j >= 10)
		{
			s[leni - 1] = j % 10 + '0';
			j = j / 10;
			leni--;
		}
		s[leni - 1] = j % 10 + '0';
		if (i < 0)
			s[0] = '-';
	}
	return (s);
}

char	*ft_itoa(int i)
{
	char	*s;
	int		leni;

	leni = ft_nblen(i);
	s = (char *) malloc(sizeof (char) * leni);
	if (s == NULL)
		return (NULL);
	s = ft_miitoa(s, i, leni);
	return (s);
}
