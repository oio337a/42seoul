/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:40:17 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/18 18:04:38 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_deque *stack_a)
{
	add_rear(stack_a,
		stack_a->data[find_idx(stack_a->front + 1, stack_a->len)]);
	delete_front(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rb(t_deque *stack_b)
{
	add_rear(stack_b,
		stack_b->data[find_idx(stack_b->front + 1, stack_b->len)]);
	delete_front(stack_b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rr(t_deque *stack_a, t_deque *stack_b)
{
	add_rear(stack_a,
		stack_a->data[find_idx(stack_a->front + 1, stack_a->len)]);
	delete_front(stack_a);
	add_rear(stack_b,
		stack_b->data[find_idx(stack_b->front + 1, stack_b->len)]);
	delete_front(stack_b);
	ft_putendl_fd("rr", STDOUT_FILENO);
}
