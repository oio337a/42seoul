/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:32:48 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/24 17:43:15 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "server.h"

t_box	g_res;

void	catching_sig(int signo)
{
	if (signo == SIGUSR1)
		g_res.sum |= 0;
	else
		g_res.sum |= 1;
	++(g_res.phase);
	if (g_res.phase == 8)
	{
		write(1, &(g_res.sum), 1);
		g_res.phase = 0;
		g_res.sum = 0;
	}
	g_res.sum <<= 1;
}

int	main(void)
{
	write(1, "server's PID : ", 16);
	ft_putnbr(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, catching_sig);
	signal(SIGUSR2, catching_sig);
	while (1)
		pause();
	return (0);
}
