/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:47:45 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/19 20:16:22 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_front(t_deque *q, int data)
{
	q->data[q->front] = data;
	q->front = (q->front - 1 + q->len) % q->len;
}

void	add_rear(t_deque *q, int data)
{
	q->rear = find_idx(q->rear + 1, q->len);
	q->data[q->rear] = data;
}

void	delete_front(t_deque *q)
{
	int	now;

	now = q->front;
	q->front = (q->front + 1) % q->len;
}

void	delete_rear(t_deque *q)
{
	int	now;

	now = q->rear;
	q->rear = (q->rear - 1 + q->len) % q->len;
}

int	find_idx(int i, int len)
{
	return (i % len);
}
