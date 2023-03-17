/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:29:24 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/16 15:31:56 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    start_lunch(void *philo)
{
    return ;
}

void    ft_init(t_data *data)
{
    int i;

    i = 0;
    while(i <= data->nb_philo)
    {
        data->philo[i].pos = i + 1;
        data->philo[i].nb_times_eat = 0;
        i++;
        data->philo[i].lfork = i;
        if (i == data->nb_philo)
            data->philo[i].rfork = 1;
        else
            data->philo[i].rfork = i + 1;
    }
}

int create_thread(t_data *data)
{
    int i;

    i = 1;
    while(i <= data->nb_philo)
    {
        pthread_create(&data->philo->thread_philo, NULL, start_lunch, &data->philo[i]);
        i++;
    }
    return (1);
}

int init_mutex(t_data *data)
{
    int i;

    i = 1;
    while(i <= data->nb_philo)
    {
        pthread_mutex_init(forks[i], NULL);
        i++;
    }
}