/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:37:15 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:37:17 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_n(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_print_c('-');
		n = -n;
	}
	if (n >= 10)
	{
		len += ft_print_n((n / 10));
		len += ft_print_n((n % 10));
	}
	else
		len += ft_print_c(n + '0');
	return (len);
}
