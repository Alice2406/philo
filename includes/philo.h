/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:54:58 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/27 19:15:03 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_arg {
	int				nb_philo;
	int				time_eat;
	int				time_sleep;
	int				time_dead;
	int				nb_eat;
	long int		start_time;
	int				nb_p_finish;
	int				stop;
	pthread_mutex_t	death;
	pthread_mutex_t	eat;
	pthread_mutex_t	writing;
	pthread_mutex_t	finish;
}				t_arg;

typedef struct s_philo {
	int				nb_times_ate;
	int				finish;
	int				pos;
	int				start_eat;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	lfork;
	t_arg			*arg;
	pthread_t		philo_dead_id;
	pthread_t		thread_philo;
}				t_philo;

typedef struct s_data {
	struct s_arg	arg;
	struct s_philo	*philo;
}				t_data;

int			create_thread(t_data *data);
void		ft_init(t_data *data);
void		ft_error(char *msg, t_data *data, int free_philos);
long int	get_time(void);
int			ft_usleep(long int ms_time);
void		routine(t_philo *philo);
void		ft_write(char *msg, t_philo *philo);
void		sleep_think(t_philo *philo);
int	philo_shrodinger(t_philo *philo);

#endif