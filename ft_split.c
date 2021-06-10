/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:20:58 by abensett          #+#    #+#             */
/*   Updated: 2021/06/10 17:56:31 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *str, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && str[i])
			j = 1;
		if (str[i] == c)
		{
			while (str[i] == c && str[i])
				i++;
			if (str[i])
				count++;
		}
		else
			i++;
	}
	return (count + j);
}

static	char	*ft_dup_word(char *str, char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = 0;
	while (str[i] && str[i] != c)
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, str, i + 1);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**tab;

	i = -1;
	words = ft_countwords((char *)s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (++i < words)
	{
		while (s[0] == c)
			s++;
		tab[i] = ft_dup_word((char *)s, c);
		if (!tab[i])
		{
			while (i > 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		s += ft_strlen(tab[i]);
	}
	tab[i] = NULL;
	return (tab);
}
