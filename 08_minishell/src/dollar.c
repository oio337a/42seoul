/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:37:42 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/27 22:26:12 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*find_value(char *dollar, t_envp *envp, int *idx)
{
	t_envp	*head;
	char	*key;
	int		i;

	i = 1;
	while (dollar[i] && (ft_isalnum(dollar[i]) || dollar[i] == '_'))
		i++;
	key = ft_substr(dollar, 1, i - 1);
	*idx += ft_strlen(key);
	head = envp;
	while (head != NULL)
	{
		if (!ft_strcmp(key, head->key))
		{
			free(key);
			return (ft_strdup(head->value));
		}
		head = head->next;
	}
	free(key);
	return (ft_strdup(""));
}

static int	check_edges(char next, char **str, int *i)
{
	if (ft_isdigit(next))
		*i += 2;
	else if (next == '$' || next == '?')
		next_dollar(next, str, i);
	else if ((!ft_isalnum(next) && next != '_') || next == '\0')
	{
		*str = ft_strjoin_free(*str, "$");
		*i += 1;
	}
	else
		return (0);
	return (1);
}

static void	quote_flag(int *flag, char c)
{
	if (c == '\"' && *flag == 1)
		*flag = 2;
	else if (c == '\"' && *flag == 2)
		*flag = 1;
	if (c == '\'' && *flag == 1)
		*flag = 0;
	else if (c == '\'' && *flag == 0)
		*flag = 1;
}

static char	*ft_strappend_free(char *str, char c)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	ret = ft_safe_malloc(len + 2);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[len] = c;
	ret[len + 1] = '\0';
	free(str);
	return (ret);
}

char	*parse_dollar(char *str, t_envp *head)
{
	char	*ret;
	char	*value;
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	ret = ft_strdup("");
	while (str[i])
	{
		quote_flag(&flag, str[i]);
		if (str[i] == '$' && flag >= 1)
		{
			if (check_edges(str[i + 1], &ret, &i))
				continue ;
			value = find_value(str + i, head, &i);
			ret = ft_strjoin_free(ret, value);
			free(value);
		}
		else
			ret = ft_strappend_free(ret, str[i]);
		i++;
	}
	return (ret);
}
