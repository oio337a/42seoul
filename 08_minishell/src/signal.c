/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:03:30 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/27 13:56:53 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ctrl_d(void)
{
	write(1, "exit\n", 5);
	exit(0);
}

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_last_exit_code = 1;
	}
}

void	wait_handler(int signum)
{
	if (signum == SIGINT)
		write(1, "\n", 1);
}

void	set_signal(t_signal mode)
{
	if (mode == CHILD)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (mode == WAITING)
	{
		signal(SIGINT, wait_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == HEREDOC)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == GENERAL)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
	}
}
