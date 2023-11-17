/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:36:43 by cacarval          #+#    #+#             */
/*   Updated: 2023/11/17 12:36:47 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_syntax_checker(t_minishell *ms, t_token *token)
{
	t_token	*curr;
	t_token	*next;

	curr = token;
	if (curr->type == T_PIPE)
		return (ft_perror(ms, E_SYNTAX, NO, NULL));
	while (curr && curr->next)
	{
		next = curr->next;
		if (curr->type != T_OTHER && next->type != T_OTHER)
		{
			if (curr->type == T_PIPE && next->type != T_PIPE)
				;
			else
				return (ft_perror(ms, E_SYNTAX, NO, NULL));
		}
		curr = curr->next;
	}
	if (curr->type != T_OTHER)
		return (ft_perror(ms, E_SYNTAX, NO, NULL));
	return (EXIT_SUCCESS);
}
