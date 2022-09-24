/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:57:00 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/24 15:58:27 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	receive_ans(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (signo == SIGUSR1)
	{
		write(1, "PID : ", 7);
		ft_putnbr(info->si_pid, 1);
		write(1, " success sending\n", 18);
	}
	else
	{
		write(1, "PID : ", 7);
		ft_putnbr(info->si_pid, 1);
		write(1, " try again.\n", 13);
		exit(0);
	}
}

void	trans_to_binary(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1000);
	}
}

void	sending_msg(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		trans_to_binary(pid, str[i]);
	trans_to_binary(pid, 0);
}

void	waiting_msg(int signo)
{
	struct sigaction	act;

	if (signo == SIGUSR1)
	{
		act.sa_sigaction = receive_ans;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
	}
	else
	{
		write(1, "try again.\n", 13);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	if (ac < 3)
		return (-1);
	(void)signal(SIGUSR1, waiting_msg);
	(void)signal(SIGUSR2, waiting_msg);
	if (kill(ft_atoi(av[1]), SIGUSR1) == -1)
		exit(1);
	pause();
	sending_msg(ft_atoi(av[1]), av[2]);
	return (0);
}
