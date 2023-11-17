/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:36:50 by cacarval          #+#    #+#             */
/*   Updated: 2023/11/17 12:41:49 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*ft_new_token(char *input, t_type type)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	if (!new_token)
		return (NULL);
	new_token->content = ft_strdup(input);
	if (!new_token->content)
	{
		free(new_token);
		return (NULL);
	}
	new_token->type = type;
	new_token->prev = NULL;
	new_token->next = NULL;
	return (new_token);
}

void	ft_add_token_back(t_token **token_lst, t_token *new_token)
{
	t_token	*current;

	if (!*token_lst)
	{
		*token_lst = new_token;
		return ;
	}
	current = *token_lst;
	while (current && current->next)
		current = current->next;
	current->next = new_token;
	new_token->prev = current;
}
