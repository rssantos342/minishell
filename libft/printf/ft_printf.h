/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:36:03 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 13:10:29 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// --------------------------------- INCLUDES ----------------------------------

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

// -------------------------------- PROTOTYPES ---------------------------------

int	ft_printf(const char *data, ...);
int	ft_print_c(char c);
int	ft_print_s(char *s);
int	ft_print_p(unsigned long n);
int	ft_print_n(long n);
int	ft_print_u(unsigned int n);
int	ft_print_x(unsigned long n, char base);

#endif
