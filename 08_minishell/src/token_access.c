/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:05:20 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/28 11:07:26 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_free_var(t_pipe *var)
{
	int	i;

	i = 0;
	while (var->filename[i])
	{
		unlink(var->filename[i]);
		free(var->filename[i++]);
	}
	free(var->filename);
	free(var->doc_cnt);
	free(var);
}

static void	child_process(t_info *head, t_envp **env, t_pipe *var, int i)
{
	t_info	*splited_token;

	set_signal(CHILD);
	if (head->type == PIPE)
		head = head->next;
	splited_token = get_token(&head, var, i);
	if (i == var->total_pipe - 1)
		(dup2(STDOUT_FILENO, var->fd[1]), close(var->fd[1]));
	if (!var->flag)
	{
		close(var->fd[0]);
		(dup2(var->fd[1], STDOUT_FILENO), close(var->fd[1]));
	}
	execve_token(splited_token, env, var->pid);
	list_delete(&splited_token);
}

static int	parent_process(t_pipe *var)
{
	set_signal(WAITING);
	dup2(var->fd[0], STDIN_FILENO);
	(close(var->fd[0]), close(var->fd[1]));
	return (1);
}

static void	let_go(t_info *head, t_pipe *var, t_envp **env)
{
	int	i;

	i = 0;
	while (i < var->total_pipe)
	{
		if (i > 0)
			move_list(&head);
		if (pipe(var->fd) == -1)
			syntax_errno("|");
		var->pid = fork();
		if (var->pid == 0)
		{
			if (var->here_doc_sig == 1)
				exit(1);
			child_process(head, env, var, i);
		}
		else
			if (!parent_process(var))
				break ;
		i++;
	}
	wait_process(var);
	set_signal(GENERAL);
}

void	pipex(t_info *token, t_envp **env)
{
	t_info	*head;
	t_pipe	*var;

	head = token;
	var = get_pipe_info(head);
	if (list_count_heredoc(head))
		get_heredoc_file(head, *env, var);
	if (var->total_pipe == 1 && is_builtin(head))
	{
		access_builtin(head, env, var);
		ft_free_var(var);
		return ;
	}
	let_go(head, var, env);
	dup2(var->stdin_back, STDIN_FILENO);
	dup2(var->stdout_back, STDOUT_FILENO);
	ft_free_var(var);
}
