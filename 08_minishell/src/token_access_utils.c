/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_access_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:39:57 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/27 21:13:48 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	move_heredoc(t_info **token, int pipe)
{
	while (pipe)
	{
		if ((*token)->type == PIPE)
			pipe--;
		(*token) = (*token)->next;
	}
}

void	move_list(t_info **token)
{
	while (*token)
	{
		if ((*token)->type == PIPE)
			break ;
		(*token) = (*token)->next;
	}
	if ((*token) != NULL)
		(*token) = (*token)->next;
}

int	list_count_heredoc(t_info *token)
{
	t_info	*head;
	int		cnt;

	head = token;
	cnt = 0;
	while (head)
	{
		if (head->type == HEREDOC_IN)
			return (++cnt);
		cnt++;
		head = head->next;
	}
	return (0);
}

int	get_heredoc_pipe(t_info *token, int cnt)
{
	t_info	*head;
	int		pipe;

	pipe = 0;
	head = token;
	while (cnt--)
	{
		if (head->type == PIPE)
			pipe++;
		head = head->next;
	}
	return (pipe);
}

void	execve_token(t_info *token, t_envp **env, pid_t pid)
{
	char	**cmd;
	int		len;
	int		i;
	t_info	*head;
	char	**envp_arr;

	len = list_size(token);
	head = token;
	i = 0;
	envp_arr = envp_to_arr(*env);
	if (!builtin(token, env, pid))
	{
		cmd = (char **)malloc(sizeof(char *) * (len + 1));
		while (head)
		{
			cmd[i] = ft_strdup(head->cmd);
			i++;
			head = head->next;
		}
		cmd[i] = 0;
		if (execve(get_cmd(cmd[0], *env), cmd, envp_arr) == -1)
			exit(g_last_exit_code);
		ft_free(cmd);
	}
}
