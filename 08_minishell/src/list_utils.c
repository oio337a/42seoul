/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:03:34 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/22 18:12:30 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_info	*init_list(void)
{
	t_info	*info;

	info = (t_info *)ft_safe_malloc(sizeof(t_info));
	info->next = NULL;
	info->cmd = NULL;
	info->type = 0;
	return (info);
}

void	insert_list(t_info *info, char *cmd, int type)
{
	t_info	*head;

	head = info;
	if (head->cmd == NULL)
	{
		head->cmd = ft_strdup(cmd);
		head->type = type;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = (t_info *)ft_safe_malloc(sizeof(t_info));
		head->next->cmd = ft_strdup(cmd);
		head->next->type = type;
		head->next->next = NULL;
	}
}

void	list_delete(t_info **info)
{
	t_info	*tmp;

	while (*info)
	{
		tmp = (*info)->next;
		free((*info)->cmd);
		free(*info);
		*info = tmp;
	}
}

int	list_size(t_info *info)
{
	t_info	*head;
	int		i;

	head = info;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}
