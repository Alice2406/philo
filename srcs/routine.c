/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:11:22 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/28 16:11:27 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleep_think(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->arg->writing) != 0)
		return (0);
	ft_write("is sleeping", philo);
	if (pthread_mutex_unlock(&philo->arg->writing) != 0)
		return (0);
	ft_usleep(philo->arg->time_sleep);
	if (pthread_mutex_lock(&philo->arg->writing) != 0)
		return (0);
	ft_write("is thinking", philo);
	if (pthread_mutex_unlock(&philo->arg->writing) != 0)
		return (0);
	return (1);
}

int	eat_time(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->arg->writing) != 0)
		return (0);
	ft_write("is eating", philo);
	if (pthread_mutex_unlock(&philo->arg->writing) != 0)
		return (0);
	if (pthread_mutex_lock(&philo->arg->eat) != 0)
		return (0);
	philo->start_eat = get_time();
	if (pthread_mutex_unlock(&philo->arg->eat) != 0)
		return (0);
	ft_usleep(philo->arg->time_eat);
	return (1);
}

int	routine(t_philo *philo)
{
	if (!(philo->pos % 2))
		if (pthread_mutex_lock(&philo->lfork) != 0)
			return (0);
	if (pthread_mutex_lock(&philo->arg->writing) != 0)
		return (0);
	ft_write("has taken a fork", philo);
	if (pthread_mutex_unlock(&philo->arg->writing) != 0)
		return (0);
	if (!philo->rfork)
	{
		ft_usleep(philo->arg->time_dead * 2);
		return (0);
	}
	if (pthread_mutex_lock(philo->rfork) != 0)
		return (0);
	if ((philo->pos % 2))
		if (pthread_mutex_lock(&philo->lfork) != 0)
			return (0);
	if (pthread_mutex_lock(&philo->arg->writing) != 0)
		return (0);
	ft_write("has taken a fork", philo);
	if (pthread_mutex_unlock(&philo->arg->writing) != 0)
		return (0);
	if (eat_time(philo) == 0)
		return (0);
	if ((philo->pos % 2))
		if (pthread_mutex_unlock(&philo->lfork) != 0)
			return (0);
	if (pthread_mutex_unlock(philo->rfork) != 0)
		return (0);
	if (!(philo->pos % 2))
		if (pthread_mutex_unlock(&philo->lfork) != 0)
			return (0);
	if (sleep_think(philo) == 0)
		return (0);
	return (1);
}
