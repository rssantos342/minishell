/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:44:57 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:45:01 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;

	i = ft_strlen(s);
	c1 = c;
	while (i >= 0)
	{
		if (s[i] == c1)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	return (NULL);
}
