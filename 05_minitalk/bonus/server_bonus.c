/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:57:25 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/24 15:59:18 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "server_bonus.h"

t_box	g_res;

void	new_client(int pid)
{
	g_res.client_pid = pid;
	kill(g_res.client_pid, SIGUSR1);
}

void	catching_sig(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (g_res.client_pid == -1)
		new_client(info->si_pid);
	else if (g_res.client_pid == info->si_pid)
	{
		if (signo == SIGUSR1)
			g_res.sum |= 0;
		else
			g_res.sum |= 1;
		++(g_res.phase);
		if (g_res.phase == 8)
		{
			write(1, &(g_res.sum), 1);
			if (!(g_res.sum))
			{
				kill(info->si_pid, SIGUSR1);
				g_res.client_pid = -1;
			}
			g_res.phase = 0;
			g_res.sum = 0;
		}
		g_res.sum <<= 1;
	}
	else
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = catching_sig;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	g_res.client_pid = -1;
	write(1, "server's PID : ", 16);
	ft_putnbr(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
