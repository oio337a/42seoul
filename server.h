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