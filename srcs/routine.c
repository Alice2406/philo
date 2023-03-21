/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:11:22 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/21 19:37:20 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->lfork);
	pthread_mutex_lock(&philo->writing);
    ft_write("has taken a fork", philo);
	pthread_mutex_unlock(&philo->writing);
    ft_usleep(200);
    pthread_mutex_unlock(&philo->lfork);
}