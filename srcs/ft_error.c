/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:02 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/28 16:26:27 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *msg, t_data *data, int free_philos)
{
	printf("Error : %s\n", msg);
	if (free_philos)
		free(data->philo);
	if (data)
		free(data);
}

void	stop_code(t_data *data)
{
	int i;

	i = -1;
	while (philo_shrodinger2(data))
		ft_usleep(1);
	while (++i < data->arg.nb_philo)
		pthread_join(data->philo[i].thread_philo, NULL);
	pthread_mutex_destroy(&data->arg.writing);
	i = -1;
	while (++i < data->arg.nb_philo)
		pthread_mutex_destroy(&data->philo[i].lfork);
	if (data->arg.stop == 2)
		printf("Each philosopher ate %d time(s)\n", data->arg.nb_eat);
	free(data->philo);
}