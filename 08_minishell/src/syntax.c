/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:05:00 by suhwpark          #+#    #+#             */
/*   Updated: 2023/03/27 22:36:15 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	validate_quote_all(t_info *token)
{
	t_info	*head;

	head = token;
	while (head)
	{
		if (!head->cmd || !check_quote_couple(head->cmd))
			return (0);
		head = head->next;
	}
	return (1);
}

void	syntax_errno(char *cmd)
{
	ft_putstr_fd(ERROR_COLOR, STDIN_FILENO);
	ft_putstr_fd("Nakishell: ", STDERR);
	ft_putstr_fd("syntax error near unexpected token `", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd("'\n", STDERR);
	g_last_exit_code = 258;
}

int	check_syntax(t_info *token)
{
	t_info	*head;

	head = token;
	if (head->type == PIPE)
	{
		syntax_errno((head->cmd));
		return (0);
	}
	while (head)
	{
		if (!vaildate_type(head))
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_pipe_count(t_info *token)
{
	t_info	*head;
	int		cnt;

	head = token;
	cnt = 0;
	while (head)
	{
		if (head->type == PIPE)
			cnt++;
		head = head->next;
	}
	return (cnt);
}
