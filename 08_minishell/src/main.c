/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:25:48 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/28 13:27:50 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_last_exit_code = 0;

static void	show_naki(void)
{
	int		fd;
	char	*line;

	fd = open("naki.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_putstr_fd(WELCOME_COLOR, STDIN_FILENO);
		ft_putstr_fd(line, STDOUT_FILENO);
		free(line);
	}
	write(1, "\n\n", 2);
	close(fd);
}

void	execute(char *str, t_info *info, t_envp **envp_head)
{
	char	*parsed;

	add_history(str);
	parsed = parse_dollar(str, *envp_head);
	str_tokenize(info, parsed);
	if (validate_quote_all(info))
	{
		clear_quote_in_token(info);
		if (check_syntax(info))
			pipex(info, envp_head);
	}
	else
		common_errno(info->cmd, 1);
	list_delete(&info);
	free(parsed);
}

static int	init_main(int ac, char **av)
{
	if (ac != 1 && av)
		return (0);
	set_signal(GENERAL);
	show_naki();
	return (1);
}

static void	continue_free(char *str, t_info *info)
{
	free(str);
	free(info);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;
	t_info	*info;
	t_envp	*envp_head;

	if (!init_main(ac, av))
		return (0);
	envp_head = set_envp(envp);
	dup2(STDIN_FILENO, STDIN);
	dup2(STDOUT_FILENO, STDOUT);
	while (1)
	{
		info = init_list();
		str = readline(PROMPT_COLOR "Nakishell$: " COMMAND_COLOR);
		if (!str)
			ctrl_d();
		if (*str == '\0' || !modu_spacebar_ya(str))
		{
			continue_free(str, info);
			continue ;
		}
		execute(str, info, &envp_head);
		free(str);
	}
	return (0);
}
