/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algorithm3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:39:31 by sohyupar          #+#    #+#             */
/*   Updated: 2023/02/06 15:15:36 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_rrb(t_deque *a_stack, t_deque *b_stack, int rra_cnt, int rrb_cnt)
{
	int	a_size;

	rra_cnt = rra_cnt - rrb_cnt;
	a_size = get_stack_size(a_stack);
	if (rra_cnt >= a_size / 2)
	{
		rra_cnt = a_size - rra_cnt;
		while (rra_cnt && rrb_cnt && (rra_cnt-- && rrb_cnt--))
			rrr(a_stack, b_stack);
		if (rra_cnt < rrb_cnt)
		{
			while (rrb_cnt && rrb_cnt--)
				rrb(b_stack);
		}
		else if (rrb_cnt < rra_cnt)
		{
			while (rra_cnt && rra_cnt--)
				rra(a_stack);
		}
	}
	util_rrb(a_stack, b_stack, rra_cnt, rrb_cnt);
}

void	use_rb(t_deque *a_stack, t_deque *b_stack, int ra_cnt, int rb_cnt)
{
	int	a_size;

	a_size = get_stack_size(a_stack);
	ra_cnt = ra_cnt - rb_cnt;
	if (ra_cnt <= a_size / 2)
		use_rr(a_stack, b_stack, ra_cnt, rb_cnt);
	else
	{
		ra_cnt = a_size - ra_cnt;
		while (ra_cnt > 0 && ra_cnt--)
			rra(a_stack);
		while (rb_cnt > 0 && rb_cnt--)
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
