/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:54:58 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/16 15:25:04 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo {
    int nb_times_eat;
    int pos;
    int rfork;
    int lfork;
    pthread_t thread_philo;
}               t_philo;

typedef struct s_data {
    int nb_philo;
    struct s_philo *philo;
    phtread_mutex_t *forks
}               t_data;

void    ft_init(t_data *data);
void    ft_error(char *msg, t_data *data, int free_philos);

#endif