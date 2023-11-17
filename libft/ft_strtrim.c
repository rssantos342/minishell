/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:45:05 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:45:10 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	b;
	size_t	e;

	if (!s1 || !set)
		return (NULL);
	b = 0;
	while (ft_strchr(set, s1[b]) && s1[b])
		b++;
	e = ft_strlen(s1);
	while (ft_strchr(set, s1[e - 1]) && e > b)
		e--;
	new = (char *)malloc((sizeof(char)) * (e - b + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (b < e)
	{
		new[i] = s1[b];
		i++;
		b++;
	}
	new[i] = '\0';
	return (new);
}
