/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:11:22 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/27 18:04:02 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->writing);
	ft_write("is sleeping", philo);
	pthread_mutex_unlock(&philo->arg->writing);
	ft_usleep(philo->arg->time_sleep);
	pthread_mutex_lock(&philo->arg->writing);
	ft_write("is thinking", philo);
	pthread_mutex_unlock(&philo->arg->writing);
}

void	eat_time(t_philo *philo)
{
	pthread_mutex_unlock(&philo->arg->writing);
	ft_write("is eating", philo);
	pthread_mutex_lock(&philo->arg->eat);
	philo->nb_times_ate++;
	pthread_mutex_lock(&philo->arg->finish);
	if (philo->finish != 1 && philo->arg->nb_eat != -1 && philo->nb_times_ate == philo->arg->nb_eat)
	{
		philo->finish = 1;
		philo->arg->nb_p_finish++;
	}
	pthread_mutex_unlock(&philo->arg->finish);
	philo->start_eat = get_time();
	pthread_mutex_unlock(&philo->arg->eat);
	ft_usleep(philo->arg->time_eat);
}

void	routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->lfork);
	pthread_mutex_lock(&philo->arg->writing);
	ft_write("has taken a fork", philo);
	pthread_mutex_unlock(&philo->arg->writing);
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_lock(&philo->arg->writing);
	ft_write("has taken a fork", philo);
	if (philo->finish == 0)
		eat_time(philo);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(&philo->lfork);
	sleep_think(philo);
}
