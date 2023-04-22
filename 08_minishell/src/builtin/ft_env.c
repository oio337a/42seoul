/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:30:54 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/27 20:59:41 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	g_exit_status;

void	ft_env(t_info *cmd, t_envp *head)
{
	t_envp	*tmp;

	tmp = head;
	if (cmd->next != NULL)
	{
		ft_putstr_fd("env: ", STDOUT_FILENO);
		ft_putstr_fd(cmd->next->cmd, STDOUT_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDOUT_FILENO);
		g_exit_status = 127;
		return ;
	}
	while (tmp)
	{
		if (tmp->value != NULL)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	g_last_exit_code = 0;
	return ;
}
