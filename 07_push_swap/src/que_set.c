/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:22:23 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/27 16:42:31 by yongmipa         ###   ########seoul.kr  */
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
