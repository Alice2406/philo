/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:54:58 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/19 15:44:59 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_arg {
    int nb_philo;
    int time_eat;
    int time_sleep;
    int time_dead;
    int nb_eat;
    int finish; //all philo ate nb_eat 
}               t_arg;

typedef struct s_philo {
    int nb_times_ate;
    int pos;
    pthread_mutex_t *rfork;
    pthread_mutex_t lfork;
    pthread_mutex_t writing;
    t_arg   *arg;
    pthread_t thread_philo;
}               t_philo;

typedef struct s_data {
    struct s_arg    arg;
    struct s_philo  *philo;
}               t_data;

void    ft_init(t_data *data);
void    ft_error(char *msg, t_data *data, int free_philos);
int create_thread(t_data *data);

#endif