/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quote_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:02:24 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/27 16:07:40 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	find_next_quote(char *line, char quote, int quote_idx)
{
	int	next_idx;

	next_idx = quote_idx + 1;
	while (line[next_idx])
	{
		if (line[next_idx] == quote)
			return (next_idx);
		next_idx++;
	}
	return (-1);
}

int	here_quote(char *line)
{
	int	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == '\'' || line[len] == '\"')
			break ;
		len++;
	}
	return (len);
}

char	*get_full_token(t_info *cmd)
{
	t_info	*head;
	char	*full_token;

	head = cmd;
	full_token = ft_strdup("");
	while (head != NULL)
	{
		full_token = ft_strjoin_free(full_token, head->cmd);
		head = head->next;
	}
	list_delete(&cmd);
	return (full_token);
}

int	is_quote(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\"' || s[i] == '\'')
			return (i);
		i++;
	}
	return (-1);
}
