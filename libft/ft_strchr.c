/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:42:49 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:42:53 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;

	i = 0;
	c1 = c;
	while (s[i])
	{
		if (s[i] == c1)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == c1)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
