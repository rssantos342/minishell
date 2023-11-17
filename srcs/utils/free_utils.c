/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:37:53 by cacarval          #+#    #+#             */
/*   Updated: 2023/11/17 12:42:57 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_token_lst(t_token **token_lst)
{
	t_token	*current;
	t_token	*next;

	if (!*token_lst)
		return ;
	current = *token_lst;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*token_lst = NULL;
}

void	ft_free_cmd_lst(t_cmd **cmd_table)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!*cmd_table)
		return ;
	current = *cmd_table;
	while (current)
	{
		next = current->next;
		ft_free_str_array(current->args);
		free(current->cmd);
		ft_free_str_array(current->f_redin);
		ft_free_str_array(current->f_redout);
		free(current->t_redin);
		free(current->t_redout);
		free(current);
		current = next;
	}
	*cmd_table = NULL;
}

void	ft_free_env_lst(t_env **env_lst)
{
	t_env	*current;
	t_env	*next;

	if (!*env_lst)
		return ;
	current = *env_lst;
	while (current)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	*env_lst = NULL;
}

void	ft_free_str_array(char **str_array)
{
	int	i;

	i = 0;
	if (!str_array)
		return ;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}

void	ft_free_pipes(t_minishell *ms)
{
	int	i;

	i = 0;
	while (i < ms->n_pipes)
	{
		if (ms->pipe_fd[i])
			free(ms->pipe_fd[i]);
		i++;
	}
	if (ms->pipe_fd)
		free(ms->pipe_fd);
	if (ms->pid)
		free(ms->pid);
}
