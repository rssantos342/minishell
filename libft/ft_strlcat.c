/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:43:27 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:43:31 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;
	size_t	t;
	size_t	n;

	if ((dest == NULL) && (size == 0))
		return (0);
	s = ft_strlen(src);
	d = ft_strlen(dest);
	if (size < d)
		return (s + size);
	i = 0;
	n = size - d;
	t = d + s;
	while (((i + 1) < n) && src[i])
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (t);
}
