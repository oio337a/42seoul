/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:00:37 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/27 17:59:45 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_envp	*init_envp(void)
{
	t_envp	*envp;

	envp = (t_envp *)ft_safe_malloc(sizeof(t_envp));
	envp->next = NULL;
	envp->key = NULL;
	envp->value = NULL;
	return (envp);
}

int	check_dupkey(t_envp *envp, char *key)
{
	t_envp	*head;

	head = envp;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, key) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

void	insert_envp(t_envp *envp, char *key, char *value)
{
	t_envp	*head;

	head = envp;
	if (head->key == NULL)
	{
		head->key = ft_strdup(key);
		head->value = ft_strdup(value);
		return ;
	}
	if (check_dupkey(envp, key))
	{
		while (ft_strcmp(head->key, key) != 0)
			head = head->next;
		free(head->value);
		head->value = ft_strdup(value);
		return ;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = (t_envp *)ft_safe_malloc(sizeof(t_envp));
	head->next->key = ft_strdup(key);
	head->next->value = ft_strdup(value);
	head->next->next = NULL;
}

void	append_envp(t_envp *envp, char *key, char *value)
{
	t_envp	*head;

	head = envp;
	while (head->next)
	{
		if (ft_strcmp(head->key, key) == 0)
			break ;
		head = head->next;
	}
	if (head->next == NULL)
	{
		if (ft_strcmp(head->key, key) == 0)
			head->value = ft_strjoin_free(head->value, value);
		else
			insert_envp(envp, key, value);
	}
	else
		head->value = ft_strjoin_free(head->value, value);
}

t_envp	*set_envp(char **envp)
{
	t_envp	*head;
	char	*key;
	char	*value;
	int		i;
	int		j;

	i = 0;
	head = init_envp();
	while (envp[i])
	{
		j = ft_strchr_int(envp[i], '=');
		key = ft_substr(envp[i], 0, j);
		value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j + 1);
		insert_envp(head, key, value);
		free(key);
		free(value);
		i++;
	}
	value = find_envp(head, "HOME");
	insert_envp(head, "OLDPWD", value);
	return (head);
}
