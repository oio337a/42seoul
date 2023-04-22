/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:07:01 by yongmipa          #+#    #+#             */
/*   Updated: 2023/04/20 17:28:10 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_number_of_meals(t_philo *philo)
{
	if (!philo->info->must_eat)
		return ;
	++(philo->amount_eat);
	if (philo->amount_eat == philo->info->must_eat)
	{
		pthread_mutex_lock(&(philo->info->philo_mutex));
		++(philo->info->meals);
		if (philo->info->meals == philo->info->num)
			philo->info->end_flag = 2;
		pthread_mutex_unlock(&(philo->info->philo_mutex));
	}
	return ;
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_msg(philo->info->start_time, philo, PICK);
	pthread_mutex_lock(philo->rfork);
	print_msg(philo->info->start_time, philo, PICK);
	print_msg(philo->info->start_time, philo, EATING);
	pthread_mutex_lock(&(philo->info)->philo_mutex);
	philo->last_eating = relative_time();
	pthread_mutex_unlock(&(philo->info)->philo_mutex);
	check_number_of_meals(philo);
	ft_usleep(relative_time(), philo->info->t_eat);
}

static void	sleeping(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	print_msg(philo->info->start_time, philo, SLEEPING);
	ft_usleep(relative_time(), philo->info->t_sleep);
	print_msg(philo->info->start_time, philo, THINKING);
}

int	is_dead(t_info *info)
{
	pthread_mutex_lock(&(info->philo_print));
	if (info->end_flag)
	{
		pthread_mutex_unlock(&(info->philo_print));
		return (1);
	}
	pthread_mutex_unlock(&(info->philo_print));
	return (0);
}

void	*routine(t_philo *philo)
{
	while (!is_dead(philo->info))
	{
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}
