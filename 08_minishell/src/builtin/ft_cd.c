/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:30:09 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/28 13:27:02 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_home(t_envp *envp)
{
	char	*path;

	path = find_envp(envp, "HOME");
	if (path)
		return (path);
	return (NULL);
}

static char	*get_oldpwd(t_envp *envp)
{
	char	*path;

	path = find_envp(envp, "OLDPWD");
	if (path)
	{
		printf("%s\n", path);
		return (path);
	}
	cd_errno("OLDPWD", 2);
	return (NULL);
}

static void	set_newpwd(t_envp *envp, char *old_pwd)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	insert_envp(envp, "PWD", new_pwd);
	insert_envp(envp, "OLDPWD", old_pwd);
	free(new_pwd);
	g_last_exit_code = 0;
}

void	ft_cd(t_info *arg, t_envp *envp)
{
	char	*path;
	char	*old_pwd;
	t_info	*tmp;

	tmp = arg;
	if (tmp->next == NULL || ft_strcmp(tmp->next->cmd, "~") == 0 || \
	ft_strcmp(tmp->next->cmd, "") == 0)
	{
		path = get_home(envp);
		if (!path)
			cd_errno("HOME", 2);
	}
	else if (ft_strcmp(tmp->next->cmd, "-") == 0)
		path = get_oldpwd(envp);
	else
		path = tmp->next->cmd;
	if (!path)
		return ;
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) == 0)
		set_newpwd(envp, old_pwd);
	else
		cd_errno(path, 1);
	free(old_pwd);
}
