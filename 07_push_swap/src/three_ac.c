/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_ac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:49:36 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/19 23:37:01 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	set_three(t_deque *stack, int first, int mid, int last)
{
	if (stack->data[first] < stack->data[last]
		&& stack->data[last] < stack->data[mid])
		return (42);
	if (stack->data[mid] < stack->data[first]
		&& stack->data[first] < stack->data[last])
		return (43);
	if (stack->data[first] < stack->data[mid]
		&& stack->data[last] < stack->data[first])
		return (44);
	if (stack->data[mid] < stack->data[last]
		&& stack->data[last] < stack->data[first])
		return (45);
	if (stack->data[mid] < stack->data[first]
		&& stack->data[last] < stack->data[mid])
		return (46);
	return (0);
}
