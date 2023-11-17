/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:36:52 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:36:57 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_print_u((n / 10));
		len += ft_print_u((n % 10));
	}
	else
		len += ft_print_c(n + '0');
	return (len);
}
