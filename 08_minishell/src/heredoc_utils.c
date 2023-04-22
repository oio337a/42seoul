/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:49:35 by suhwpark          #+#    #+#             */
/*   Updated: 2023/03/27 14:43:57 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_heredoc(t_info *token)
{
	t_info	*head;
	int		count;

	head = token;
	count = 0;
	while (head)
	{	
		if (head->type == HEREDOC_IN)
			count++;
		head = head->next;
	}
	return (count);
}

char	**file_name(t_info *token)
{
	int		len;
	int		i;
	char	**filename;
	char	*tmp;

	i = 0;
	len = count_heredoc(token);
	filename = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		filename[i] = ft_strdup(".heredoc");
		tmp = ft_itoa(i);
		filename[i] = ft_strjoin_free(filename[i], tmp);
		free(tmp);
		i++;
	}
	filename[i] = 0;
	return (filename);
}

void	get_heredoc_file(t_info *token, t_envp *env, t_pipe *var)
{
	int		i;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		i = 0;
		set_signal(HEREDOC);
		while (token)
		{
			if (token->type == HEREDOC_IN)
				here_doc(token->next->cmd, env, var->filename[i++]);
			token = token->next;
		}
		exit(g_last_exit_code);
	}
	else
	{
		set_signal(WAITING);
		waitpid(pid, &status, 0);
		if (status == 2)
			var->here_doc_sig = 1;
	}
	set_signal(GENERAL);
}
