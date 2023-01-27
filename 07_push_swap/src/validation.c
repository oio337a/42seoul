/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:07:16 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/19 17:40:37 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_duplication(t_deque *stack)
{
	int	i;
	int	j;

	i = 0;
	while (++i < stack->len - 1)
	{
		j = i;
		while (++j < stack->len)
		{
			if (stack->data[i] == stack->data[j])
				exit(error());
		}
	}
}

int	check_sorted(t_deque *stack_a, int *arr)
{
	int	i;

	i = -1;
	while (++i < stack_a->len - 1)
	{
		if (arr[i] != stack_a->data[i + 1])
			return (1);
	}
	return (0);
}
