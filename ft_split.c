/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:20:58 by abensett          #+#    #+#             */
/*   Updated: 2021/06/09 15:47:18 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_separator(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

int	ft_numwords(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

char	*ft_dupword(char const *s, int n)
{
	char	*str;

	str = (char *)malloc((sizeof(char) * (n + 1)));
	if (!(s))
		return (NULL);
	str[n] = '\0';
	while (n--)
		str[n] = s[n];
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int	i;
	int	j;
	int	k;

	tab = (char **)malloc((ft_numwords(s, c) + 1) * sizeof (char *));
	if (!(tab))
		return (NULL);
	k = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && ft_separator(s[j], c))
			j++;
		i = j;
		while (s[j] && !ft_separator(s[j], c))
			j++;
		if (j > i)
			tab[k++] = ft_dupword(s + i, j - i);
	}
	tab[ft_numwords(s, c)] = 0;
	return (tab);
}
