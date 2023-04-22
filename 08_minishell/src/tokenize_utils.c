/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:59:28 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/28 13:35:04 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	modu_spacebar_ya(char *line)
{
	while (*line)
	{
		if (*line != 32 && !(*line >= 9 && *line <= 13))
			return (1);
		line++;
	}
	return (0);
}

static void	go_after_quote(char **line, char *tmp, char *bulk, t_info *info)
{
	bulk = get_after_quote(*line, tmp);
	*line += (ft_strlen(bulk) - ft_strlen(tmp));
	insert_list(info, bulk, WORD);
	free(bulk);
	free(tmp);
}

void	quote_process(t_info *info, char **line)
{
	char	*bulk;
	char	*tmp;

	bulk = quote_bulk(*line, **line);
	if (!ft_strlen(bulk))
	{
		*line += 2;
		while ((*line)[0] && (*line)[0] == '\"')
		{
			if ((*line)[1] != '\"')
				break ;
			*line += 2;
		}
	}
	else
		*line += ft_strlen(bulk);
	tmp = bulk;
	if ((*line)[0] && (*line)[0] != ' ')
	{
		go_after_quote(line, tmp, bulk, info);
		return ;
	}
	insert_list(info, bulk, WORD);
	free(bulk);
}

int	reminder_in_quote(char quote, int i, char *line)
{
	if (quote == '\"')
	{
		if (find_next_quote(line, '\"', i) == -1)
			;
		else
			i = find_next_quote(line, '\"', i);
	}
	else if (quote == '\'')
	{
		if (find_next_quote(line, '\'', i) == -1)
			;
		else
			i = find_next_quote(line, '\'', i);
	}
	return (i);
}

void	ft_remainder(t_info *info, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*line)[i] && is_not_whitespace((*line)[i]) && (*line)[i] != '>'
		&& (*line)[i] != '<' && (*line)[i] != '|')
		i = reminder_in_quote((*line)[i], i, *line) + 1;
	tmp = ft_substr(*line, 0, i);
	*line += ft_strlen(tmp) - 1;
	insert_list(info, tmp, WORD);
	free(tmp);
}
