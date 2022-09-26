/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:17:17 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/26 19:22:43 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	trans_to_binary(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
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

int	main(int ac, char **av)
{
	if (ac < 3)
	{
		write(1, "Error : ./client [PID] [Messege]\n", 33);
		return (-1);
	}
	sending_msg(ft_atoi(av[1]), av[2]);
	return (0);
}
