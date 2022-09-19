/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:40:29 by yongmipa          #+#    #+#             */
/*   Updated: 2022/09/19 19:40:32 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_request
{
	struct sigaction	phase_read_connection;
	struct sigaction	phase_read_msglen;
	struct sigaction	phase_read_msg;
	pid_t				clipid;
	unsigned int		len;
	unsigned int		len_bc;
	char				*msg;
	unsigned int		msg_ix;
	unsigned int		msg_bc;
}	t_request;

extern t_request	g_request;

#endif