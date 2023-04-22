/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:32:13 by suhwpark          #+#    #+#             */
/*   Updated: 2023/03/28 13:35:31 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*quote_bulk(char *line, char c)
{
	int		i;
	char	*bulk;

	i = 1;
	if (line[i] == c)
	{
		bulk = ft_strdup("");
		return (bulk);
	}
	while (line[i] && line[i] != c)
		i++;
	bulk = ft_substr(line, 0, i + 1);
	return (bulk);
}

char	*get_after_quote(char *line, char *bulk)
{
	char	*tmp;
	char	*real_bulk;
	int		i;
	int		linelen;

	linelen = ft_strlen(line);
	i = 0;
	while (is_not_whitespace(line[i]))
	{
		i = reminder_in_quote(line[i], i, line);
		if (i >= linelen)
		{
			i = linelen;
			break ;
		}
		i++;
	}
	tmp = ft_substr(line, 0, i);
	real_bulk = ft_strjoin(bulk, tmp);
	free(tmp);
	return (real_bulk);
}

static void	only_redir(t_info *info, char **line)
{
	if (**line == '>')
		insert_list(info, ">", REDIR_OUT);
	else if (**line == '<')
		insert_list(info, "<", REDIR_IN);
	else
		insert_list(info, "|", PIPE);
}

static void	redir_check(t_info *info, char **line)
{
	char	*temp;
	int		type;

	type = HEREDOC_IN;
	if (*(*line + 1) == **line)
	{
		if (*(*line + 1) == '>')
			type = HEREDOC_OUT;
		if (*(*line + 1) == '|')
			type = WORD;
		temp = ft_substr(*line, 0, 2);
		insert_list(info, temp, type);
		free(temp);
		if (*(*line + 2) != ' ' || *(*line + 2) != '\0' \
		|| *(*line + 2) != '<' || *(*line + 2) != '>')
			*line += 1;
		else
			*line += 2;
	}
	else
		only_redir(info, line);
}

void	str_tokenize(t_info *info, char *line)
{
	while (*line)
	{
		if (*line == '>' || *line == '<' || *line == '|')
			redir_check(info, &line);
		else if (*line == '\"' || *line == '\'')
			quote_process(info, &line);
		else if (*line != '>' && *line != '<' && *line != '|' && *line != ' ')
			ft_remainder(info, &line);
		if (*line == '\0')
			break ;
		line++;
	}
}
