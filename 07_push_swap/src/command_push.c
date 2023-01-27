/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:34:50 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/27 16:41:55 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_deque *stack_a, t_deque *stack_b)
{
	if (!is_empty(stack_b))
	{
		add_front(stack_a,
			stack_b->data[find_idx(stack_b->front + 1, stack_b->len)]);
		delete_front(stack_b);
	}
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(t_deque *stack_a, t_deque *stack_b)
{
	if (!is_empty(stack_a))
	{
		add_front(stack_b,
			stack_a->data[find_idx(stack_a->front + 1, stack_a->len)]);
		delete_front(stack_a);
	}
	ft_putendl_fd("pb", STDOUT_FILENO);
}
