/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:45:10 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/25 12:08:54 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	util_rrb(t_deque *a, t_deque *b, int ra_count, int rrb_count)
{
	while (ra_count && ra_count--)
		ra(a);
	while (rrb_count && rrb_count--)
		rrb(b);
}

void	use_rr(t_deque *a_stack, t_deque *b_stack, int ra_count, int rb_count)
{
	while (ra_count && rb_count && (ra_count-- && rb_count--))
		rr(a_stack, b_stack);
	while (rb_count > 0 && rb_count--)
		rb(b_stack);
	while (ra_count > 0 && ra_count--)
		ra(a_stack);
}

int	cost_calculate2(t_deque *a_stack, int b_data, int i)
{
	int	cost;

	if (b_data < a_stack->data[a_stack->min])
	{
		cost = ((a_stack->min - (a_stack->front + 1) + a_stack->len)
				% a_stack->len);
		if (cost > get_stack_size(a_stack) / 2)
			cost = get_stack_size(a_stack) - cost;
		return (cost + i);
	}
	else if (b_data > a_stack->data[a_stack->max])
	{
		cost = ((a_stack->max - (a_stack->front + 1) + a_stack->len)
				% a_stack->len);
		if (cost > get_stack_size(a_stack) / 2)
			cost = get_stack_size(a_stack) - cost;
		return (cost + 1 + i);
	}
	else
	{
		cost = count_mid_cost(a_stack, b_data);
		if (cost > get_stack_size(a_stack) / 2)
			cost = get_stack_size(a_stack) - cost;
		return (cost + i);
	}
}

int	*b_stack_cost2(t_deque *a_stack, t_deque *b_stack)
{
	int	*cost;
	int	b_len;
	int	i;
	int	b_data;
	int	tmp;

	tmp = 0;
	b_len = get_stack_size(b_stack);
	cost = (int *)malloc(sizeof(int) * b_len);
	i = -1;
	while (++i < b_len)
	{
		b_data = b_stack
			->data[find_idx((b_stack->front + 1) + i, b_stack->len)];
		if (i > b_len / 2)
			tmp = b_len - i;
		else
			tmp = i;
		cost[i] = cost_calculate2(a_stack, b_data, tmp);
	}
	return (cost);
}

void	preprocess_utils(t_deque *a_stack, t_deque *b_stack, int *pivot, int i)
{
	while (++i < a_stack->len)
	{
		if (get_stack_size(a_stack) == 3)
			break ;
		if (a_stack->data[i] <= pivot[0])
		{
			if (is_empty(b_stack))
				pb(a_stack, b_stack);
			else
			{	
				pb(a_stack, b_stack);
				rb(b_stack);
			}
		}
		else if (a_stack->data[i] > pivot[0] && a_stack->data[i] < pivot[1])
			pb(a_stack, b_stack);
		else
			ra(a_stack);
	}
}
