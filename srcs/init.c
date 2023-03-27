/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:29:24 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/27 13:42:38 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->death);
	if (philo->arg->dead == 1 || (get_time() - philo->start_eat >= philo->arg->time_dead))
	{
		philo->arg->dead = 1;
		pthread_mutex_unlock(&philo->arg->dead);
		return(0);
	}
	pthread_mutex_unlock(&philo->arg->dead);
	return (1);
}

void	*start_lunch(void *s)
{
	t_philo	*philo;

	philo = (t_philo *)s;
	if (philo->pos % 2 == 0)
		ft_usleep(philo->arg->time_eat / 10);
	while (philo_alive(philo))
	{
		routine(philo);
		if (philo->arg->nb_p_finish == philo->arg->nb_philo)
		{
			pthread_mutex_lock(&philo->arg->writing);
			printf("Everybody ate %d times", philo->arg->nb_eat);
			pthread_mutex_unlock(&philo->arg->writing);
			exit(0);
		}
	}
	return (NULL);
}

void	ft_init(t_data *data)
{
	int	i;

	i = 0;
	data->arg.start_time = get_time();
	data->arg.nb_p_finish = 0;
	data->arg.dead = 0;
	pthread_mutex_init(&data->arg.writing, NULL);
	pthread_mutex_init(&data->arg.eat, NULL);
	pthread_mutex_init(&data->arg.death, NULL);
	while (i < data->arg.nb_philo)
	{
		data->philo[i].start_eat = data->arg.start_time;
		data->philo[i].finish = 0;
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

int	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg.nb_philo)
	{
		data->philo[i].arg = &data->arg;
		pthread_create(&data->philo[i].thread_philo, NULL,
			start_lunch, &data->philo[i]);
		i++;
	}
	return (1);
}
