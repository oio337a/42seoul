/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:28:43 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/27 16:42:09 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	ft_free(char *strs[])
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
