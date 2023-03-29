/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:11:35 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/29 10:26:46 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_param(char **av, int ac, t_data *data)
{
	if (!is_digit(av))
		return (0);
	data->arg.nb_philo = (int)ft_atol(av[1]);
	data->arg.time_dead = (int)ft_atol(av[2]);
	data->arg.time_eat = (int)ft_atol(av[3]);
	data->arg.time_sleep = (int)ft_atol(av[4]);
	if (ac == 6)
	{
		data->arg.nb_eat = (int)ft_atol(av[5]);
		if (data->arg.nb_eat == 0)
			return (0);
	}
	else
		data->arg.nb_eat = -1;
	if (data->arg.nb_philo < 1 || data->arg.time_dead <= 0
		|| data->arg.time_eat <= 0 || data->arg.time_sleep <= 0
		|| data->arg.nb_philo > 200)
		return (0);
	return (1);
}

int	philo_shrodinger2(t_data *data)
{
	pthread_mutex_lock(&data->arg.death);
	if (data->arg.stop)
	{
		pthread_mutex_unlock(&data->arg.death);
		return (0);
	}
	pthread_mutex_unlock(&data->arg.death);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 6 && ac != 5)
		return (0);
	if (!ft_check_param(av, ac, &data))
		return (0);
	data.philo = malloc(sizeof(t_philo) * data.arg.nb_philo);
	if (!data.philo)
		ft_error("malloc struct failed", &data, 0);
	if (ft_init(&data) == 0 || create_thread(&data) == 0)
	{
		free(data.philo);
		return (0);
	}
	stop_code(&data);
}
