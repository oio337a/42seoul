/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:36:28 by yongmipa          #+#    #+#             */
/*   Updated: 2022/12/29 17:19:37 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

int	print_error(char *msg)
{
	ft_putendl_fd("error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	ft_allfree(void *ptr[])
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
