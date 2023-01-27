/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algorithm1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:44:29 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/25 11:44:39 by sohyupar         ###   ########.fr       */
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
		return ;
	}
	// while (++i < a_stack->len)
	// {
	// 	if (get_stack_size(a_stack) == 3)
	// 		break ;
	// 	if (a_stack->data[i] <= pivot[0])
	// 	{
	// 		if (is_empty(b_stack))
	// 			pb(a_stack, b_stack);
	// 		else
	// 		{	
	// 			pb(a_stack, b_stack);
	// 			rb(b_stack);
	// 		}
	// 	}
	// 	else if (a_stack->data[i] > pivot[0] && a_stack->data[i] < pivot[1])
	// 		pb(a_stack, b_stack);
	// 	else
	// 		ra(a_stack);
	// }
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
}
