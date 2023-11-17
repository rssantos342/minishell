/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:41:43 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:41:47 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	if (d > s)
	{
		while (n--)
		{
			*(d + n) = *(s + n);
		}
	}
	else
	{
		while (n--)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dest);
}
