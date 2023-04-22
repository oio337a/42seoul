/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:00:06 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/24 18:06:49 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**set_path(char *cmd, t_envp *envp)
{
	char	*path;

	path = find_envp(envp, "PATH");
	if (!path)
	{
		common_errno(cmd, 2);
		return (NULL);
	}
	return (ft_split(path, ':'));
}

static char	*is_folder(char *cmd, char **path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		if (!ft_strncmp(cmd, path[i], ft_strlen(cmd)))
			return (NULL);
	}
	return (cmd);
}

static char	**setting_cmd(char *cmd, t_envp *envp)
{
	char	**envp_in_list;

	envp_in_list = set_path(cmd, envp);
	if (!is_folder(cmd, envp_in_list))
	{
		common_errno(cmd, 21);
		g_last_exit_code = 126;
		return (NULL);
	}
	return (envp_in_list);
}

static char	*return_cmd(char **envp, char *cmd_path)
{
	int		i;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		tmp = ft_strjoin(envp[i], cmd_path);
		if (access(tmp, X_OK) != -1)
		{
			free(cmd_path);
			return (tmp);
		}
		free(tmp);
	}
	return (NULL);
}

char	*get_cmd(char *cmd, t_envp *envp)
{
	char	*tmp;
	char	**envp_in_list;

	if (!ft_strlen(cmd))
	{
		common_errno(cmd, 127);
		return (NULL);
	}
	envp_in_list = setting_cmd(cmd, envp);
	if (access(cmd, X_OK) != -1)
		return (cmd);
	else if (!ft_strncmp("/", cmd, 1))
	{
		common_errno(cmd, 2);
		g_last_exit_code = 127;
		return (NULL);
	}
	tmp = return_cmd(envp_in_list, ft_strjoin("/", cmd));
	if (!tmp)
	{
		common_errno(cmd, 127);
		return (NULL);
	}
	return (tmp);
}
