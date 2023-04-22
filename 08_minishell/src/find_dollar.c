/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:00:43 by suhwpark          #+#    #+#             */
/*   Updated: 2023/03/27 22:28:25 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_quote_couple(char *token)
{
	int	i;
	int	next;

	i = 0;
	next = 0;
	while (token[i])
	{
		if (token[i] == '\'')
		{
			next = find_next_quote(token, '\'', i);
			if (next == -1)
				return (0);
			i = next;
		}
		if (token[i] == '\"')
		{
			next = find_next_quote(token, '\"', i);
			if (next == -1)
				return (0);
			i = next;
		}
		i++;
	}
	return (1);
}

void	next_dollar(char next, char **str, int *i)
{
	char	*value;

	if (next == '$')
	{
		value = ft_itoa(getpid());
		*i += 2;
	}
	else
	{
		value = ft_itoa(g_last_exit_code);
		*i += 2;
	}
	*str = ft_strjoin_free(*str, value);
	free(value);
}
