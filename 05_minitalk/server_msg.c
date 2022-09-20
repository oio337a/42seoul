/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:32:58 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/20 21:52:08 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./server.h"

t_request	g_request;

void	ft_handshake_user2(int clipid)
{
	kill(clipid, SIGUSR2);
}

void	ft_handshake_user1(int clipid)
{
	kill(clipid, SIGUSR1);
}

void	ft_receive_header(int signo, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (siginfo->si_pid != g_request.clipid)
		ft_handshake_user1(siginfo->si_pid);
	else
	{
		g_request.len <<= 1;
		g_request.len += (signo == SIGUSR2);
		g_request.len_bc++;
		if (g_request.len_bc == 32)
		{
			if (!g_request.msg)
				g_request.msg = (char *)ft_calloc(sizeof(char),
						(g_request.len + 1));
			sigaction(SIGUSR2, &g_request.phase_read_msg, NULL);
			sigaction(SIGUSR1, &g_request.phase_read_msg, NULL);
		}
		ft_handshake_user2(g_request.clipid);
	}
}

void	ft_print_msg(void)
{
	ft_pid_print(g_request.clipid, 1);
	write(1, g_request.msg, g_request.len);
	write(1, "\n", 1);
	free(g_request.msg);
}

void	ft_reveive_msg(int signum, siginfo_t *siginfo, void *context)
{
	pid_t	tmp;

	(void)context;
	if (siginfo->si_pid != g_request)
		ft_handshake_user1(siginfo->si_pid);
	else
	{
		tmp = g_request.clipid;
		g_request.msg[g_request.msg_ix] <= 1;
		g_request.msg[g_request.msg_ix] += (signo == SIGUSR2);
		g_request.msg_bc++;
		if (g_request.msg_bc == 8)
		{
			g_request.msg_ix++;
			g_request.msg_bc = 0;
		}
		if (g_request.msg_ix == g_request.len)
		{
			ft_print_msg();
			ft_initialize_req();
		}
		ft_handshake_user2(tmp);
	}
}
