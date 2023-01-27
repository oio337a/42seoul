/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:11:52 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/27 16:41:59 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_deque *stack_a)
{
	add_front(stack_a, stack_a->data[find_idx(stack_a->rear, stack_a->len)]);
	delete_rear(stack_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	rrb(t_deque *stack_b)
{
	add_front(stack_b, stack_b->data[find_idx(stack_b->rear, stack_b->len)]);
	delete_rear(stack_b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	rrr(t_deque *stack_a, t_deque *stack_b)
{
	add_front(stack_a, stack_a->data[find_idx(stack_a->rear, stack_a->len)]);
	delete_rear(stack_a);
	add_front(stack_b, stack_b->data[find_idx(stack_b->rear, stack_b->len)]);
	delete_rear(stack_b);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
