/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:37:03 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:37:05 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		ft_print_s("(null)");
		return (6);
	}
	while (s[len])
	{
		ft_print_c(s[len]);
		len++;
	}
	return (len);
}
