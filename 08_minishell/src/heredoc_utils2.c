/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:53:45 by suhwpark          #+#    #+#             */
/*   Updated: 2023/03/27 15:07:02 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_heredoc(t_info *token)
{
	t_info	*head;
	int		cnt;

	cnt = 0;
	head = token;
	while (head && head->type != PIPE)
	{
		if (head->type == HEREDOC_IN)
			cnt++;
		head = head->next;
	}
	return (cnt);
}

int	*process_heredoc_cnt(t_info *token, int total_pipe)
{
	t_info	*head;
	int		*cnt;
	int		i;
	int		here;

	i = 0;
	head = token;
	here = 0;
	cnt = (int *)malloc(sizeof(int) * total_pipe);
	while (head)
	{
		if (head->type == HEREDOC_IN)
			here++;
		if (head->type == PIPE)
		{
			cnt[i] = here;
			here = 0;
			i++;
		}
		head = head->next;
	}
	cnt[i] = here;
	return (cnt);
}
