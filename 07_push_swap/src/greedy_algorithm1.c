/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algorithm1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:44:29 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/27 16:42:14 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	get_stack_size(t_deque *stack)
{
	if (stack->front < stack->rear)
		return (stack->rear - stack->front);
	return (stack->len - ft_abs(stack->front - stack->rear));
}

void	set_position(t_deque *stack, int *first, int *mid, int *last)
{
	*first = find_idx(stack->front + 1, stack->len);
	*mid = find_idx(stack->front + 2, stack->len);
	*last = find_idx(stack->rear, stack->len);
}

void	a_stack_sort(t_deque *stack)
{
	int	first;
	int	mid;
	int	last;
	int	judge;

	set_position(stack, &first, &mid, &last);
	judge = set_three(stack, first, mid, last);
	if (judge == 42)
	{
		sa(stack);
		ra(stack);
	}
	if (judge == 43)
		sa(stack);
	if (judge == 44)
		rra(stack);
	if (judge == 45)
		ra(stack);
	if (judge == 46)
	{
		sa(stack);
		rra(stack);
	}
}

void	preprocess(t_deque *a_stack, t_deque *b_stack)
{
	int	*pivot;
	int	i;

	pivot = get_pivot(a_stack);
	i = 0;
	if (get_stack_size(a_stack) == 3 && is_empty(b_stack))
	{
		a_stack_sort(a_stack);
		free(pivot);
		return ;
	}
	preprocess_utils(a_stack, b_stack, pivot, i);
	if (get_stack_size(a_stack) > 3)
	{
		while (1)
		{
			if (get_stack_size(a_stack) == 3)
				break ;
			pb(a_stack, b_stack);
		}
	}
	a_stack_sort(a_stack);
	free(pivot);
}
