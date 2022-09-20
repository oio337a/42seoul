/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:17:17 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/20 22:32:59 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./client.h"

t_request	g_request;

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
