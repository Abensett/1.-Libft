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
	int	i;

	i = 0;
	if (c == charset)
		return (1);
	return (0);
}

int	ft_numwords(char const *str, char charset)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && ft_separator(str[i], charset))
			i++;
		while (str[i] && !ft_separator(str[i], charset))
		{
			i++;
			j++;
		}
		if (j > 0)
			nb++;
	}
	return (nb);
}

char	*ft_dupword(char const *s, int n)
{
	char	*str;

	str = malloc((sizeof(char) * (n + 1)));
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
	int		i;
	int		j;
	int		lenw;

	tab = malloc ((ft_numwords(s, c) + 1) * sizeof (char *));
	if (!(tab))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_numwords(s, c))
	{
		lenw = 0;
		while (s[j] && ft_separator(s[j], c))
			j++;
		while (s[j] && !ft_separator(s[j], c))
		{	
			j++;
			lenw++;
		}
		tab[i++] = ft_dupword(s + j - lenw, lenw);
		if (!tab[i])
			return (NULL);
	}
	tab[ft_numwords(s, c)] = 0;
	return (tab);
}
