/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:36:03 by cacarval          #+#    #+#             */
/*   Updated: 2023/11/17 12:41:29 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_command_table_creator(t_minishell *ms)
{
	t_token	*curr;

	curr = ms->token_lst;
	while (curr)
	{
		if (curr->type == T_OTHER)
			curr->type = T_COMMAND;
		else if (curr->type == T_REDIR_IN)
			curr->next->type = T_FILE_IN;
		else if (curr->type == T_REDIR_OUT)
			curr->next->type = T_FILE_TR;
		else if (curr->type == T_REDIR2_OUT)
			curr->next->type = T_FILE_AP;
		else if (curr->type == T_REDIR2_IN)
			curr->next->type = T_HEREDOC;
		curr = curr->next;
	}
	if (ft_command_table_helper(ms) == EXIT_NO_CMD)
		return (EXIT_NO_CMD);
	return (EXIT_SUCCESS);
}

int	ft_command_table_helper(t_minishell *ms)
{
	int		n_args;
	t_token	*curr;
	t_token	*first_cmd;

	n_args = 0;
	curr = ms->token_lst;
	while (curr)
	{
		n_args = 0;
		first_cmd = curr;
		while (curr->next && curr->type != T_PIPE)
		{
			if (curr->type == T_COMMAND)
				n_args++;
			curr = curr->next;
		}
		if (curr->type == T_COMMAND)
			n_args++;
		if (ft_command_table_exception(ms, first_cmd, n_args) == EXIT_NO_CMD)
			return (EXIT_NO_CMD);
		ft_add_cmd_back(&ms->cmd_lst, ft_new_cmd(first_cmd, n_args));
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}

int	ft_command_table_exception(t_minishell *ms, t_token *first, int n_args)
{
	t_token	*curr;

	curr = first;
	if (n_args == 0)
	{
		if (first->type == T_EMPTY
			&& (!first->next || first->next->type == T_PIPE))
			return (EXIT_NO_CMD);
		while (curr)
		{
			if (curr->type == T_EMPTY && curr->next)
				curr = curr->next;
			if (curr->type == T_FILE_IN)
				ft_open_fd(ms, NULL, curr->content, T_FILE_IN);
			if (curr->type == T_FILE_TR)
				ft_open_fd(ms, NULL, curr->content, T_FILE_TR);
			if (curr->type == T_HEREDOC)
				ft_handle_heredoc(ms, curr->content);
			if (curr->type == T_FILE_AP)
				ft_open_fd(ms, NULL, curr->content, T_FILE_AP);
			curr = curr->next;
		}
		return (EXIT_NO_CMD);
	}
	return (EXIT_SUCCESS);
}
