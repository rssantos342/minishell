/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:34:56 by cacarval          #+#    #+#             */
/*   Updated: 2023/11/17 12:34:57 by cacarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_minishell *ms, t_cmd *curr)
{
	char	cwd[4096];

	if (ft_cmd_has_valid_option(curr->args) == FALSE)
		ft_free_all(ms, YES, YES);
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	g_exit_status = 0;
	ft_free_all(ms, YES, YES);
}
