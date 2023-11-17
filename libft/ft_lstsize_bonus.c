/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:41:03 by ride-sou          #+#    #+#             */
/*   Updated: 2023/11/17 12:41:07 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*ptr;

	counter = 0;
	ptr = lst;
	while (ptr)
	{
		counter++;
		ptr = ptr->next;
	}
	return (counter);
}
