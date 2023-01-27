/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyupar <sohyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:06:30 by sohyupar          #+#    #+#             */
/*   Updated: 2023/01/25 12:09:06 by sohyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR -1

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_deque
{
	int	*data;
	int	front;
	int	rear;
	int	len;
	int	min;
	int	max;
}t_deque;

int		*get_pivot(t_deque *q);

t_deque	*init(int len);
void	add_front(t_deque *q, int data);
void	add_rear(t_deque *q, int data);
void	delete_front(t_deque *q);
void	delete_rear(t_deque *q);
int		find_idx(int i, int len);

void	pa(t_deque *stack_a, t_deque *stack_b);
void	pb(t_deque *stack_a, t_deque *stack_b);
void	sa(t_deque *stack_b);
void	sb(t_deque *stack_a);
void	ra(t_deque *stack_a);
void	rb(t_deque *stack_b);
void	rr(t_deque *stack_a, t_deque *stack_b);
void	rra(t_deque *stack_a);
void	rrb(t_deque *stack_b);
void	rrr(t_deque *stack_a, t_deque *stack_b);

void	indexing_a_stack(t_deque *a_stack, int *tmp);
int		*get_pivot(t_deque *a_stack);
void	tmp_sort(int *arr, int start, int end);

void	check_duplication(t_deque *stack);
int		check_sorted(t_deque *stack, int *arr);

int		get_stack_size(t_deque *stack);
void	set_position(t_deque *stack, int *first, int *mid, int *last);
void	a_stack_sort(t_deque *stack);
void	preprocess(t_deque *a_stack, t_deque *b_stack);

int		error(void);
void	ft_free(char *strs[]);
int		ft_atoi2(const char *str);
void	preprocess(t_deque *a_stack, t_deque *b_stack);
int		is_empty(t_deque *q);
int		get_stack_size(t_deque *stack);

int		cost_calculate(t_deque *a_stack, int b_data, int i);
int		count_mid_cost(t_deque *a_stack, int data);

int		*get_pivot(t_deque *a_stack);
void	indexing_a_stack(t_deque *a_stack, int *tmp);
void	tmp_sort(int *arr, int start, int end);
void	greedy_sort(t_deque *a_stack, t_deque *b_stack);

void	use_rb(t_deque *a_stack,
			t_deque *b_stack, int ra_count, int rrb_count);
void	use_rrb(t_deque *a_stack,
			t_deque *b_stack, int ra_count, int rb_count);

int		set_three(t_deque *stack, int first, int mid, int last);
int		get_a_min_index(t_deque *a_stack);
int		get_a_max_index(t_deque *a_stack);
int		ft_abs(int n);

int		cost_calculate2(t_deque *a_stack, int b_data, int i);
int		*b_stack_cost2(t_deque *a_stack, t_deque *b_stack);
void	preprocess_utils(t_deque *a, t_deque *b, int *pivot, int i);

void	util_rrb(t_deque *a, t_deque *b, int ra_count, int rrb_count);
void	use_rr(t_deque *a_stack, t_deque *b_stack, int ra_count, int rb_count);
#endif