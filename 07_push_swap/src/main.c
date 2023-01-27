/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:07:26 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/24 16:53:35 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_argu(int ac, char *av[])
{
	char	**numbers;
	int		i;
	int		num;
	int		len;

	len = 0;
	while (--ac)
	{
		if (**(++av) == '\0')
			exit(error());
		numbers = ft_split(*av, ' ');
		if (!numbers)
			exit(error());
		i = 0;
		while (numbers[i])
		{
			num = ft_atoi2(numbers[i]);
			len++;
			i++;
		}
		ft_free(numbers);
	}
	if (len == 1)
		exit(error());
	return (len);
}

static void	fill_stack(int ac, char *av[], t_deque *a_stack)
{
	char	**numbers;
	int		i;
	int		num;

	while (--ac)
	{
		if (**(++av) == '\0')
			exit(error());
		numbers = ft_split(*av, ' ');
		if (!numbers)
			exit(error());
		i = 0;
		while (numbers[i])
		{
			num = ft_atoi2(numbers[i]);
			add_rear(a_stack, num);
			i++;
		}
		ft_free(numbers);
	}
}

static void	last_sort(t_deque *a_stack)
{
	int	i;

	i = -1;
	while (++i < a_stack->len)
		if (a_stack->data[find_idx(a_stack->front + 1 + i, a_stack->len)] == 1)
			break ;
	if (i > a_stack->len / 2)
	{
		while (a_stack->data[find_idx(a_stack->front + 1, a_stack->len)] != 1)
			rra(a_stack);
	}
	else
		while (a_stack->data[find_idx(a_stack->front + 1, a_stack->len)] != 1)
			ra(a_stack);
}

int	main(int ac, char *av[])
{
	int		len;
	t_deque	*a_stack;
	t_deque	*b_stack;

	if (ac < 2)
		return (1);
	len = count_argu(ac, av);
	a_stack = init(len + 1);
	fill_stack(ac, av, a_stack);
	check_duplication(a_stack);
	if (len == 2)
	{
		if (a_stack->data[1] > a_stack->data[2])
			sa(a_stack);
		exit(0);
	}
	b_stack = init(len + 1);
	preprocess(a_stack, b_stack);
	while (!is_empty(b_stack))
		greedy_sort(a_stack, b_stack);
	last_sort(a_stack);
	return (0);
}
