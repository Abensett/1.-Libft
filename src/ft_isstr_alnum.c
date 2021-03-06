/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstr_alnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:41:07 by abensett          #+#    #+#             */
/*   Updated: 2022/05/29 19:54:31 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isstr_alnum(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str))
			return (0);
		str++;
	}
	return (1);
}
