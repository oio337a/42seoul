/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:32:48 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/19 16:01:52 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_request	g_request;

void	struct_init(void)
{
	g_request.phase_read_connection.sa_sigaction = ft_receive_connection;
	g_request.phase_read_msglen.sa_sigaction = ft_receive_header;
	g_request.phase_read_msg.sa_sigaction = ft_receive_msg;
	sigemptyset(&g_request.phase_read_connection.sa_mask);
	sigemptyset(&g_request.phase_read_msglen.sa_mask);
	sigemptyset(&g_request.phase_read_msg.sa_mask);
	g_request.phase_read_connection.sa_flags = SA_SIGINFO;
	g_request.phase_read_msglen.sa_flags = SA_SIGINFO;
	g_request.phase_read_msg.sa_flags = SA_SIGINFO;
}

int	pid_print(int pid, int flag)
{
	char	*buf;

	buf = ft_itoa(pid);
	if (!buf)
		exit(1);
	if (flag == 1)
		write(1, "client pid : ", 13);
	else if (flag == 2)
		write(1, "server pid : ", 13);
	write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	free(buf);
	return (0);
}

void	ft_initialize_req(void)
{
	g_request.clipid = 0;
	g_request.len = 0;
	g_request.len_bc = 0;
	g_request.msg = NULL;
	g_request.msg_ix = 0;
	g_request.msg_bc = 0;
	sigaction(SIGUSR2, &g_request.phase_read_connection, NULL);
	sigaction(SIGUSR1, &g_request.phase_read_connection, NULL);
}

int	main(void)
{
	pid_print(getpid(), 2);
	struct_init();
	while (1)
	{
		pause();
	}
	return (0);
}
