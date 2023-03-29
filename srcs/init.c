/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:29:24 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/29 10:22:57 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_lunch(void *s)
{
	t_philo	*philo;

	philo = (t_philo *)s;
	if (philo->pos % 2 == 0)
		ft_usleep(philo->arg->time_eat / 10);
	while (philo_shrodinger(philo, 0))
	{
		if (pthread_create(&philo->philo_dead_id, NULL, philo_dead, s) != 0)
			return (NULL);
		routine(philo);
		if (pthread_detach(philo->philo_dead_id) != 0)
			return (NULL);
		if (++philo->nb_times_ate == philo->arg->nb_eat)
		{
			pthread_mutex_lock(&philo->arg->finish);
			philo->finish = 1;
			philo->arg->nb_p_finish++;
			if (philo->arg->nb_p_finish == philo->arg->nb_philo)
				philo_shrodinger(philo, 2);
			pthread_mutex_unlock(&philo->arg->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->arg.writing, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->arg.eat, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->arg.death, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->arg.finish, NULL) != 0)
		return (0);
	return (1);
}

int	ft_init(t_data *data)
{
	int	i;

	i = 0;
	data->arg.start_time = get_time();
	data->arg.nb_p_finish = 0;
	data->arg.stop = 0;
	if (init_mutex(data) == 0)
		return (0);
	while (i < data->arg.nb_philo)
	{
		data->philo[i].start_eat = data->arg.start_time;
		data->philo[i].finish = 0;
		data->philo[i].pos = i + 1;
		data->philo[i].nb_times_ate = 0;
		if (pthread_mutex_init(&data->philo[i].lfork, NULL) != 0)
			return (0);
		if (i == data->arg.nb_philo - 1)
			data->philo[i].rfork = &data->philo[0].lfork;
		else
			data->philo[i].rfork = &data->philo[i + 1].lfork;
		i++;
	}
	return (1);
}

int	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->arg.nb_philo)
	{
		data->philo[i].arg = &data->arg;
		if (pthread_create(&data->philo[i].thread_philo, NULL,
				start_lunch, &data->philo[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
