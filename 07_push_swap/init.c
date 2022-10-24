/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:36:57 by yongmipa          #+#    #+#             */
/*   Updated: 2022/10/24 15:07:00 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(void)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	tmp->next = NULL;
	return (tmp);
}

int	newnode(t_node *node, int data)
{
	t_node	*tmp;

	tmp = init_node();
	tmp->data = data;
	while (node->next != NULL)
		node = node->next;
	node->next = tmp;
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_node	*node;

	node = init_node();
	newnode(node, 1);
	newnode(node, 2);
	newnode(node, 3);
	newnode(node, 4);
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	return (0);
}
