/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:21:34 by yongmipa          #+#    #+#             */
/*   Updated: 2023/04/20 17:27:04 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	in_monitor(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->info->num)
	{
		pthread_mutex_lock(&(philo->info)->philo_mutex);
		if (relative_time() - (&philo[i])[0].last_eating >= philo->info->t_die)
		{
			print_msg(philo->info->start_time, &philo[i], DIED);
			philo->info->end_flag = 1;
			pthread_mutex_unlock(&(philo->info)->philo_mutex);
			return (1);
		}
		pthread_mutex_unlock(&(philo->info)->philo_mutex);
	}
	return (0);
}

void	monitor(t_philo *philo, pthread_t *table)
{
	int	i;

	i = -1;
	while (1)
	{
		if (in_monitor(philo))
			break ;
		pthread_mutex_lock(&(philo->info)->philo_mutex);
		if (philo->info->end_flag == 2)
		{
			pthread_mutex_unlock(&(philo->info)->philo_mutex);
			break ;
		}
		pthread_mutex_unlock(&(philo->info)->philo_mutex);
	}
	while (++i < philo[0].info->num)
		pthread_join(table[i], NULL);
}

static int	one_philo(t_philo *philo, t_info *info)
{
	print_msg(info->start_time, philo, PICK);
	ft_usleep(info->start_time, info->t_die);
	print_msg(info->start_time, philo, DIED);
	ft_free(info, philo);
	return (0);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	pthread_t	*phillo_in_table;

	if (ac < 5 || ac > 6)
		return (-1);
	if (!validate_info(ac, av, &info))
		return (-1);
	philo = set_philo(&info);
	if (!philo)
		return (-1);
	if (info.num == 1)
		return (one_philo(philo, &info));
	phillo_in_table = (pthread_t *)malloc(sizeof(pthread_t) * info.num);
	if (!phillo_in_table)
		return (-1);
	input_philo(&info, philo, phillo_in_table);
	return (0);
}
