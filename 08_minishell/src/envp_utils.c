/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:35:18 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/22 18:12:27 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	size_envp(t_envp *lst)
{
	int		i;
	t_envp	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	delete_envp_all(t_envp **envp)
{
	t_envp	*tmp;

	while (*envp)
	{
		tmp = (*envp)->next;
		free((*envp)->key);
		free((*envp)->value);
		free(*envp);
		*envp = tmp;
	}
}

char	**envp_to_arr(t_envp *head)
{
	t_envp	*tmp;
	char	**ret;
	int		i;

	tmp = head;
	ret = (char **)ft_safe_malloc(sizeof(char *) * (size_envp(head) + 1));
	i = 0;
	while (tmp)
	{
		ret[i] = ft_strdup(tmp->key);
		if (tmp->value)
		{
			ret[i] = ft_strjoin_free(ret[i], "=");
			ret[i] = ft_strjoin_free(ret[i], tmp->value);
		}
		tmp = tmp->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**dup_envp(t_envp *head)
{
	t_envp	*tmp;
	char	**ret;
	int		i;

	tmp = head;
	ret = (char **)ft_safe_malloc(sizeof(char *) * (size_envp(head) + 1));
	i = 0;
	while (tmp)
	{
		ret[i] = ft_strdup(tmp->key);
		if (tmp->value)
		{
			ret[i] = ft_strjoin_free(ret[i], "=\"");
			ret[i] = ft_strjoin_free(ret[i], tmp->value);
			ret[i] = ft_strjoin_free(ret[i], "\"");
		}
		tmp = tmp->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	*find_envp(t_envp *envp, char *key)
{
	t_envp	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (ft_strcmp(key, tmp->key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
