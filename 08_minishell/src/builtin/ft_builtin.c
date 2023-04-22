/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:01:16 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/27 21:01:33 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_info *cmd)
{
	if (ft_strcmp(cmd->cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

int	builtin(t_info *cmd, t_envp **head, pid_t pid)
{
	if (cmd->cmd[0] == '\0')
		return (0);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		ft_env(cmd, *head);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		ft_pwd(*head);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		ft_export(cmd, *head);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		ft_unset(cmd, head);
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		ft_cd(cmd, *head);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		ft_exit(cmd);
	else
		return (0);
	if (pid == 0)
		exit(g_last_exit_code);
	return (1);
}
