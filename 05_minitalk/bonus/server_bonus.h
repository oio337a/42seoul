/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:57:37 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/24 15:59:25 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

typedef struct s_box
{
	int		sum;
	int		phase;
	int		client_pid;
}	t_box;

void	ft_putnbr(int n, int fd);
void	get_client_pid(int signo, siginfo_t *info, void *context);
void	catching_sig(int signo, siginfo_t *info, void *context);

#endif