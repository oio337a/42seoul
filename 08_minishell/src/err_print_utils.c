/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:51:01 by yongmipa          #+#    #+#             */
/*   Updated: 2023/03/24 17:02:07 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	bulga(char *next_arg, int fd)
{
	ft_putstr_fd(next_arg, fd);
	ft_putstr_fd(strerror(errno), fd);
	ft_putstr_fd("\n", fd);
	g_last_exit_code = 1;
}
