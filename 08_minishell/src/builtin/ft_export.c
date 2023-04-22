/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:29:43 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/24 17:51:30 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	sort_arr(char **arr)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	len = ft_arrlen(arr);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strcmp(*(arr + i), *(arr + j)) < 0)
			{
				tmp = *(arr + j);
				*(arr + j) = *(arr + i);
				*(arr + i) = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	check_argv(char *argv)
{
	char	*key;
	int		i;
	int		plus;
	int		ret;

	i = ft_strchr_int(argv, '=');
	if (i == -1)
		return (validate_key(argv));
	plus = ft_strchr_int(argv, '+');
	if (plus != -1 && plus < i && (plus != i - 1))
		return (0);
	if (plus == i - 1)
		key = ft_substr(argv, 0, plus);
	else
		key = ft_substr(argv, 0, i);
	ret = validate_key(key);
	free(key);
	return (ret);
}

static void	set_key_value(t_envp *head, char *argv, int i, int plus)
{
	char	*key;
	char	*value;

	value = ft_substr(argv, i + 1, ft_strlen(argv) - i + 1);
	if (plus == i - 1)
	{
		key = ft_substr(argv, 0, i - 1);
		append_envp(head, key, value);
	}
	else
	{
		key = ft_substr(argv, 0, i);
		insert_envp(head, key, value);
	}
	free(key);
	free(value);
}

static int	add_envp(char *argv, t_envp *head)
{
	int		i;
	int		plus;

	if (!head || !argv)
		return (0);
	if (!check_argv(argv))
		return (envp_errno(argv));
	i = ft_strchr_int(argv, '=');
	plus = ft_strchr_int(argv, '+');
	if (i == -1)
		insert_envp(head, argv, NULL);
	else
		set_key_value(head, argv, i, plus);
	return (1);
}

void	ft_export(t_info *arg, t_envp *head)
{
	t_info	*arg_tmp;
	t_envp	*env_tmp;
	char	**arr;
	int		i;

	arg_tmp = arg;
	env_tmp = head;
	if (arg_tmp->next == NULL)
	{
		arr = dup_envp(head);
		sort_arr(arr);
		i = -1;
		while (arr[++i])
			printf("declare -x %s\n", arr[i]);
		ft_free(arr);
	}
	i = 0;
	arg_tmp = arg_tmp->next;
	while (arg_tmp)
	{
		if (!add_envp(arg_tmp->cmd, head))
			i = 1;
		arg_tmp = arg_tmp->next;
	}
	g_last_exit_code = i;
}
