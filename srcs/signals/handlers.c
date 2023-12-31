/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:37:06 by cacarval          #+#    #+#             */
/*   Updated: 2023/11/17 12:37:09 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_heredoc(int signum, t_minishell *ms)
{
	static t_minishell	*h;

	if (!signum && ms)
	{
		h = ms;
		return ;
	}
	if (signum == SIGINT)
	{
		if (h->n_pipes > 0)
			ft_free_all(h, YES, YES);
		else
			ft_free_all(h, NO, YES);
	}
}

void	ft_handler_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
	g_exit_status = 130;
}

void	ft_handler_heredoc(int signum)
{
	g_exit_status = 130;
	ft_free_heredoc(signum, NULL);
}

void	ft_handler_child(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		return ;
	}
	else if (signum == SIGQUIT)
		g_exit_status = 128 + signum;
}
