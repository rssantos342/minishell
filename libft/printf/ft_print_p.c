/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:37:09 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:37:11 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long n)
{
	int	len;

	len = 0;
	if (!n)
	{
		ft_print_s("(nil)");
		return (5);
	}
	len += ft_print_s("0x");
	len += ft_print_x(n, 'x');
	return (len);
}
