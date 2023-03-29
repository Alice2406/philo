/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:21:50 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/29 10:27:11 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_shrodinger(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->arg->death);
	if (i)
		philo->arg->stop = i;
	if (philo->arg->stop)
	{
		pthread_mutex_unlock(&philo->arg->death);
		return (0);
	}
	pthread_mutex_unlock(&philo->arg->death);
	return (1);
}

void	*philo_dead(void *s)
{
	t_philo	*philo;

	philo = (t_philo *)s;
	ft_usleep(philo->arg->time_dead + 1);
	pthread_mutex_lock(&philo->arg->eat);
	pthread_mutex_lock(&philo->arg->finish);
	if (philo_shrodinger(philo, 0) && !philo->finish
		&& (get_time() - philo->start_eat >= philo->arg->time_dead))
	{
		pthread_mutex_lock(&philo->arg->writing);
		ft_write("is died", philo);
		pthread_mutex_unlock(&philo->arg->writing);
		philo_shrodinger(philo, 1);
	}
	pthread_mutex_unlock(&philo->arg->finish);
	pthread_mutex_unlock(&philo->arg->eat);
	return (NULL);
}
