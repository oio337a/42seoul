/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:29:32 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/27 21:06:21 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	validate_key(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if ((!ft_isalnum(str[i]) && str[i] != '_'))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

static void	free_envp(t_envp **envp)
{
	free((*envp)->key);
	free((*envp)->value);
	free((*envp));
}

void	delete_envp(t_info *arg_tmp, t_envp **envp)
{
	t_envp	*tmp;
	t_envp	*before;
	t_envp	*curr;

	tmp = *envp;
	if (!ft_strcmp(arg_tmp->cmd, tmp->key))
	{
		*envp = (*envp)->next;
		free_envp(&tmp);
		return ;
	}
	while (tmp->next != NULL)
	{
		if (!ft_strcmp(arg_tmp->cmd, tmp->next->key))
		{
			before = tmp;
			curr = tmp->next;
			before->next = curr->next;
			free_envp(&curr);
		}
		else
			tmp = tmp->next;
	}
}

void	ft_unset(t_info *arg, t_envp **envp)
{
	t_info	*arg_tmp;
	int		i;

	if (!arg->next || !envp)
	{
		g_last_exit_code = 0;
		return ;
	}
	i = 0;
	arg_tmp = arg->next;
	while (arg_tmp)
	{
		if (!validate_key(arg_tmp->cmd))
		{
			i = 1;
			envp_errno(arg_tmp->cmd);
			arg_tmp = arg_tmp->next;
			continue ;
		}
		delete_envp(arg_tmp, envp);
		arg_tmp = arg_tmp->next;
	}
	g_last_exit_code = i;
}
