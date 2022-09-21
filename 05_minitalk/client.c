/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:17:17 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/21 19:57:10 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

t_request	g_request;

void	ft_receive_ping_cnt(int signo, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signo == SIGUSR1)
	{
		ft_send_connection();
	}
	if (signo == SIGUSR2)
	{
		sigaction(SIGUSR2, &g_request.phase_send_msglen, NULL);
		sigaction(SIGUSR1, &g_request.phase_send_msglen, NULL);
		ft_intbit_send(g_request.srvpid, g_request.len);
	}
}

void	ft_send_connection(void)
{
	int			sleep_checker;
	static int	tc;

	sleep_checker = 0;
	tc = 0;
	while (1)
	{
		kill(g_request.srvpid, SIGUSR2);
		sleep_checker = usleep(1000000);
		tc++;
		if (sleep_checker != 0 || tc == 31)
		{
			break ;
		}
	}
	if (tc == 31)
		ft_strerr("Error\n: the Server didn't receive client's request");
}

int	main(int ac, char **av)
{
	if (ac == 3)
		write(1, "Error\n", 6);
	g_request.srvpid = (pid_t)ft_atoi(av[1]);
	if (g_request.srvpid < 99)
		write(1, "Error : invalid server pid", 26);
	g_request.len = ft_strlen(av[2]);
	if (g_request.len <= 0)
		write(1, "Error : invalid msg", 19);
	g_request.clipid = getpid();
	g_request.msg = av[2];
	ft_pid_print(g_request.clipid, 1);
	ft_sigstruct_init();
	sigaction(SIGUSR2, &g_request.phase_send_connection, NULL);
	sigaction(SIGUSR1, &g_request.phase_send_connection, NULL);
	ft_send_connection();
	while (1)
	{
		pause();
	}
	return (0);
}
