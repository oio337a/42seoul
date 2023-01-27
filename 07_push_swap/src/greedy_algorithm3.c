/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algorithm3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:39:31 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/25 12:07:04 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_rrb(t_deque *a_stack, t_deque *b_stack, int ra_count, int rrb_count)
{
	int	a_size;

	ra_count = ra_count - rrb_count;
	a_size = get_stack_size(a_stack);
	if (ra_count >= a_size / 2)
	{
		ra_count = a_size - ra_count;
		while (ra_count && rrb_count && (ra_count-- && rrb_count--))
			rrr(a_stack, b_stack);
		if (ra_count < rrb_count)
		{
			while (rrb_count && rrb_count--)
				rrb(b_stack);
		}
		else if (rrb_count < ra_count)
		{
			while (ra_count && ra_count--)
				rra(a_stack);
		}
	}
	util_rrb(a_stack, b_stack, ra_count, rrb_count);
}

void	use_rb(t_deque *a_stack, t_deque *b_stack, int ra_count, int rb_count)
{
	int	a_size;

	a_size = get_stack_size(a_stack);
	ra_count = ra_count - rb_count;
	if (ra_count <= a_size / 2)
		use_rr(a_stack, b_stack, ra_count, rb_count);
	else
	{
		ra_count = a_size - ra_count;
		while (ra_count > 0 && ra_count--)
			rra(a_stack);
		while (rb_count > 0 && rb_count--)
			rb(b_stack);
	}
}

int	get_a_min_index(t_deque *a_stack)
{
	int	i;
	int	len;
	int	min;
	int	min_index;

	i = 0;
	min = a_stack->data[find_idx((a_stack->front + 1), a_stack->len)];
	min_index = find_idx((a_stack->front + 1), a_stack->len);
	len = get_stack_size(a_stack);
	while (++i < len)
	{
		if (a_stack
			->data[find_idx((a_stack->front + 1 + i), a_stack->len)] < min)
		{
			min = a_stack
				->data[find_idx((a_stack->front + 1 + i), a_stack->len)];
			min_index = find_idx((a_stack->front + 1 + i), a_stack->len);
		}
	}
	return (min_index);
}

int	get_a_max_index(t_deque *a_stack)
{
	int	i;
	int	len;
	int	max;
	int	max_index;

	i = 0;
	max = a_stack->data[find_idx((a_stack->front + 1), a_stack->len)];
	max_index = find_idx((a_stack->front + 1 + i), a_stack->len);
	len = get_stack_size(a_stack);
	while (++i < len)
	{
		if (a_stack
			->data[find_idx((a_stack->front + 1 + i), a_stack->len)] > max)
		{
			max = a_stack
				->data[find_idx((a_stack->front + 1 + i), a_stack->len)];
			max_index = find_idx((a_stack->front + 1 + i), a_stack->len);
		}
	}
	return (max_index);
}
