/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:29:24 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/21 19:35:26 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_dead(void)
{
    return (1);
}

void    *start_lunch(void *s)
{
    t_philo *philo;

    philo = (t_philo *)s;
    if (philo->pos % 2 == 0)
        ft_usleep(philo->arg->time_eat / 10);
    while(philo_dead())
    {
        take_forks(philo);
        // eat_time(philo);
        // sleep_think_time(philo);
        // pthread_detach(philo->thread_philo);
    }
    return (NULL);
}

void    ft_init(t_data *data)
{
    int i;

    i = 0;
    data->arg.start_time = get_time();
	pthread_mutex_init(&data->philo->writing, NULL);
    while(i < data->arg.nb_philo)
    {
        data->philo[i].pos = i + 1;
        data->philo[i].nb_times_ate = 0;
        pthread_mutex_init(&data->philo[i].lfork, NULL);
        if (i == data->arg.nb_philo - 1)
            data->philo[i].rfork = &data->philo[0].lfork;
        else
            data->philo[i].rfork = &data->philo[i + 1].lfork;
        i++;
    }
}

int create_thread(t_data *data)
{
    int i;

    i = 0;
    while(i < data->arg.nb_philo)
    {
        data->philo[i].arg = &data->arg;
        pthread_create(&data->philo[i].thread_philo, NULL, start_lunch, &data->philo[i]);
        i++;
    }
    return (1);
}
