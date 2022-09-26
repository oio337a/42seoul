/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:40:29 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/26 16:46:38 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_box
{
	int		sum;
	int		phase;
}	t_box;

void	ft_putnbr(int n, int fd);

#endif