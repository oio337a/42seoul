/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:57:16 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/19 20:16:21 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_deque *stack_a)
{
	int	tmp;
	int	next_top;

	next_top = stack_a->front + 2;
	if (!is_empty(stack_a))
	{
		tmp = stack_a->data[find_idx(stack_a->front + 1, stack_a->len)];
		stack_a->data[find_idx(stack_a->front + 1, stack_a->len)]
			= stack_a->data[(next_top) % stack_a->len];
		stack_a->data[(next_top) % stack_a->len]
			= tmp;
	}
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	sb(t_deque *stack_b)
{
	int	tmp;
	int	next_top;

	next_top = stack_b->front + 2;
	if (!is_empty(stack_b))
	{
		tmp = stack_b->data[find_idx(stack_b->front + 1, stack_b->len)];
		stack_b->data[find_idx(stack_b->front + 1, stack_b->len)]
			= stack_b->data[(next_top) % stack_b->len];
		stack_b->data[(next_top) % stack_b->len]
			= tmp;
	}
	ft_putendl_fd("sb", STDOUT_FILENO);
}
