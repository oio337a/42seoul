/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:22:23 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/25 12:36:49 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_deque	*init(int len)
{
	t_deque	*q;

	q = malloc(sizeof(t_deque));
	if (!q)
		exit(error());
	q->data = malloc(sizeof(int) * len);
	if (!q->data)
		exit(error());
	q->front = 0;
	q->rear = 0;
	q->len = len;
	q->min = 0;
	q->max = 0;
	return (q);
}

int	is_empty(t_deque *q)
{
	return (q->front == q-> rear);
}
