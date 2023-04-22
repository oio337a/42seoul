/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:06:57 by suhwpark          #+#    #+#             */
/*   Updated: 2023/03/27 22:38:59 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	common_errnos(char *cmd, int res, int type)
{
	if (type != 3)
		ft_putstr_fd("Nakishell: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	if (type == 1)
		ft_putstr_fd(": command not found", STDERR);
	else if (type == 2)
	{
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(strerror(res), STDERR);
	}
	ft_putstr_fd("\n", STDERR);
	g_last_exit_code = 127;
}

void	common_errno(char *cmd, int res)
{
	if (!cmd)
	{
		g_last_exit_code = 0;
		return ;
	}
	ft_putstr_fd(ERROR_COLOR, STDERR);
	if (res == 127)
		common_errnos(cmd, res, 1);
	else
	{
		common_errnos(cmd, res, 2);
		g_last_exit_code = 1;
	}
	ft_putstr_fd(COMMAND_COLOR, STDERR);
}

int	envp_errno(char *err_value)
{
	ft_putstr_fd(ERROR_COLOR, STDERR);
	ft_putstr_fd("Nakishell$: export: `", STDERR);
	ft_putstr_fd(err_value, STDERR);
	ft_putstr_fd("': not a valid identifier\n", STDERR);
	g_last_exit_code = 1;
	return (0);
}

void	cd_errno(char *err_value, int res)
{
	ft_putstr_fd(ERROR_COLOR, STDERR);
	ft_putstr_fd("Nakishell$: cd: ", STDERR);
	ft_putstr_fd(err_value, STDERR);
	if (res == 1)
		ft_putstr_fd(": No such directory\n", STDERR);
	else if (res == 2)
		ft_putstr_fd(": not set\n", STDERR);
	g_last_exit_code = 1;
}

void	exit_errno(int arg_status, char *cmd)
{
	ft_putstr_fd(ERROR_COLOR, STDERR);
	if (arg_status != 0)
	{
		ft_putstr_fd("Nakishell$: ", STDERR);
		ft_putstr_fd(cmd, STDERR);
		ft_putstr_fd(": too many arguments\n", STDERR);
		g_last_exit_code = 1;
	}
	else
	{
		ft_putstr_fd("Nakishell$: exit: ", STDERR);
		ft_putstr_fd(cmd, STDERR);
		ft_putstr_fd(": numeric argument required\n", STDERR);
		g_last_exit_code = 255;
		exit(g_last_exit_code);
	}
}
