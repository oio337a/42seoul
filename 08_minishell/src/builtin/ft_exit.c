/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:30:35 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/28 13:22:35 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_sec(t_info *arg)
{
	t_info	*temp;
	int		digit_idx;
	int		cmd_len;
	int		check;

	temp = malloc(sizeof(t_info));
	temp = arg->next;
	digit_idx = 0;
	cmd_len = ft_strlen(temp->cmd);
	check = ft_atoi(&temp->cmd[digit_idx]);
	if (check <= 0)
	{
		if (temp->cmd[0] == '-')
			digit_idx++;
		check *= -1;
	}
	while (check > 0)
	{
		check /= 10;
		digit_idx++;
	}
	return (digit_idx == cmd_len);
}

static int	list_get_size(t_info *lst)
{
	int		i;
	t_info	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

static void	one_arg(int check_arg, t_info *arg)
{
	if (check_arg)
	{
		g_last_exit_code = ft_atoi((arg->next)->cmd) % 256;
		exit(g_last_exit_code);
	}
	else
		exit_errno(check_arg, (arg->next)->cmd);
}

void	ft_exit(t_info *arg)
{
	int	check_arg;
	int	arg_size;

	arg_size = list_get_size(arg);
	write(2, "exit\n", 5);
	if (arg_size == 1)
		exit(g_last_exit_code);
	check_arg = check_sec(arg);
	if (arg_size >= 3)
	{
		if (check_arg)
			exit_errno(check_arg, arg->cmd);
		else
			exit_errno(check_arg, (arg->next)->cmd);
	}
	else
		one_arg(check_arg, arg);
}
