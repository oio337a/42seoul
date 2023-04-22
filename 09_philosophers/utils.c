/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmipa <yongmipa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:14:09 by yongmipa          #+#    #+#             */
/*   Updated: 2023/04/20 17:27:24 by yongmipa         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

MS	relative_time(void)
{
	struct timeval	current;

	gettimeofday(&current, 0);
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}

void	*ft_free(t_info *info, t_philo *philo)
{
	if (!philo)
	{
		pthread_mutex_destroy(&info->philo_print);
		pthread_mutex_destroy(&info->philo_mutex);
	}
	if (!info)
	{
		while (info->num--)
		{
			pthread_mutex_destroy(philo[info->num].lfork);
			pthread_mutex_destroy(philo[info->num].rfork);
		}
	}
	return (NULL);
}

void	print_msg(MS seconds, t_philo *philo, char *msg)
{
	MS	time;

	pthread_mutex_lock(&(philo->info)->philo_print);
	time = relative_time() - seconds;
	usleep(50);
	if (philo->info->end_flag)
	{
		pthread_mutex_unlock(&(philo->info)->philo_print);
		return ;
	}
	printf("%llu	%d %s\n", time, philo->p_index, msg);
	pthread_mutex_unlock(&(philo->info)->philo_print);
	printf("\033[0m");
}

MS	get_time(MS start)
{
	MS	now;

	now = relative_time();
	return (now - start);
}

void	ft_usleep(MS time, MS finish)
{
	while (get_time(time) < finish)
		usleep(100);
}
