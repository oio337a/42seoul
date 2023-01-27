/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:29:40 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/24 16:55:12 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tmp_sort(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	temp;

	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[start])
			++i;
		while (j > start && arr[j] >= arr[start])
			--j;
		if (i >= j)
			break ;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	temp = arr[j];
	arr[j] = arr[start];
	arr[start] = temp;
	tmp_sort(arr, start, j - 1);
	tmp_sort(arr, j + 1, end);
}

void	indexing_a_stack(t_deque *a_stack, int *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (++i < a_stack->len)
	{
		j = -1;
		while (++j < a_stack->len - 1)
		{
			if (a_stack->data[i] == tmp[j])
			{
				a_stack->data[i] = j + 1;
				break ;
			}
		}
	}
}

int	*get_pivot(t_deque *a_stack)
{
	int	*tmp;
	int	*pivot;
	int	i;

	tmp = (int *)malloc(sizeof(int) * a_stack->len - 1);
	pivot = (int *)malloc(sizeof(int) * 2);
	i = -1;
	while (++i < a_stack->len - 1)
		tmp[i] = a_stack->data[i + 1];
	tmp_sort(tmp, 0, a_stack->len - 2);
	if (!check_sorted(a_stack, tmp))
	{
		free(tmp);
		free(pivot);
		exit(0);
	}
	pivot[0] = (a_stack->len - 2) / 3;
	pivot[1] = (a_stack->len - 2) - ((a_stack->len - 2) / 3);
	indexing_a_stack(a_stack, tmp);
	free(tmp);
	return (pivot);
}
