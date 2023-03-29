/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:11:22 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/29 10:06:03 by aniezgod         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->arg->writing);
	ft_write("is eating", philo);
	pthread_mutex_unlock(&philo->arg->writing);
	pthread_mutex_lock(&philo->arg->eat);
	philo->start_eat = get_time();
	pthread_mutex_unlock(&philo->arg->eat);
	ft_usleep(philo->arg->time_eat);
}

void	routine(t_philo *philo)
{
	if (!(philo->pos % 2))
		pthread_mutex_lock(&philo->lfork);
	pthread_mutex_lock(&philo->arg->writing);
	ft_write("has taken a fork", philo);
	pthread_mutex_unlock(&philo->arg->writing);
	if (philo->arg->nb_philo == 1)
	{
		ft_usleep(philo->arg->time_dead * 2);
		return ;
	}
	pthread_mutex_lock(philo->rfork);
	if ((philo->pos % 2))
		pthread_mutex_lock(&philo->lfork);
	pthread_mutex_lock(&philo->arg->writing);
	ft_write("has taken a fork", philo);
	pthread_mutex_unlock(&philo->arg->writing);
	eat_time(philo);
	if ((philo->pos % 2))
		pthread_mutex_unlock(&philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	if (!(philo->pos % 2))
		pthread_mutex_unlock(&philo->lfork);
	sleep_think(philo);
}
