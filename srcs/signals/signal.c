/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:37:15 by cacarval          #+#    #+#             */
/*   Updated: 2023/11/17 12:42:40 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_signals(void)
{
	signal(SIGINT, ft_handler_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_signals_heredoc(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_signals_child(t_minishell *ms)
{
	(void) ms;
	signal(SIGINT, ft_handler_child);
	signal(SIGQUIT, ft_handler_child);
}
