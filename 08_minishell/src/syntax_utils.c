/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:10:45 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/24 18:00:51 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	error_case(t_info *head)
{
	if ((head->next) == NULL)
	{
		if (head->type == HEREDOC_IN)
			syntax_errno("<<");
		else if (head->type == HEREDOC_OUT)
			syntax_errno(">>");
		return (0);
	}
	else if ((head->next)->type != WORD)
	{
		syntax_errno(head->next->cmd);
		return (0);
	}
	return (1);
}

static int	error_case2(t_info *head)
{
	if ((head->next) == NULL)
	{
		if (head->type == REDIR_IN)
			syntax_errno("<");
		else if (head->type == REDIR_OUT)
			syntax_errno(">");
		return (0);
	}
	else if ((head->next)->type != WORD)
	{
		syntax_errno(head->next->cmd);
		return (0);
	}
	return (1);
}

int	vaildate_type(t_info *head)
{
	if (!ft_strcmp("||", head->cmd))
	{
		syntax_errno("|");
		return (0);
	}
	else if ((head->type == PIPE && ((head->next) == NULL)))
	{
		syntax_errno("|");
		return (0);
	}
	else if (head->type == HEREDOC_IN || head->type == HEREDOC_OUT)
	{
		if (!error_case(head))
			return (0);
	}
	else if (head->type == REDIR_IN || head->type == REDIR_OUT)
	{
		if (!error_case2(head))
			return (0);
	}
	return (1);
}
