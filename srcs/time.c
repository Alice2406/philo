/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:21:33 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/28 14:32:48 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	actual_time;
	long int		time;

	gettimeofday(&actual_time, NULL);
	time = (actual_time.tv_sec * 1000) + (actual_time.tv_usec / 1000);
	return (time);
}

int	ft_usleep(long int ms_time)
{
	long int	before;
	long int	after;

	before = get_time();
	after = get_time();
	while (after - before < ms_time)
	{
		usleep(ms_time / 10);
		after = get_time();
	}
	return (1);
}

void	ft_write(char *msg, t_philo *philo)
{
	if (philo_shrodinger(philo, 0))
	{
		printf("%ld ", get_time() - philo->arg->start_time);
		printf("%d ", philo->pos);
		printf("%s\n", msg);
	}
}
