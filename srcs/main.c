/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:11:35 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/21 19:36:01 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number);
}

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
        i++;
    return (i);
}

int is_digit(char **str)
{
    int i;
    int j;

    i = 1;
    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if (str[i][j] < '0' || str[i][j] > '9' || ft_strlen(str[i]) > 10)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_check_param(char **av, int ac, t_data *data)
{
    if (!is_digit(av))
        return (0);
    data->arg.nb_philo = ft_atoi(av[1]);
    data->arg.time_dead = ft_atoi(av[2]);
    data->arg.time_eat = ft_atoi(av[3]);
    data->arg.time_sleep = ft_atoi(av[4]);
    if (ac == 6)
    {
        data->arg.nb_eat = ft_atoi(av[5]);
        if (data->arg.nb_eat == 0)
            return (0);
    }
    else
        data->arg.nb_eat = -1;
    if (data->arg.nb_philo < 1 || data->arg.time_dead == 0 || data->arg.time_eat == 0
        || data->arg.time_sleep == 0)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    t_data *data;

    if (ac != 6 && ac != 5)
        return (0);
    data = malloc(sizeof(t_data));
    if (!data)
        ft_error("malloc struct failed", NULL, 0);
    if(!ft_check_param(av, ac, data))
        return (0);
    data->philo = malloc(sizeof(t_philo) * data->arg.nb_philo);
    if (!data->philo)
        ft_error("malloc struct failed", data, 0);
    ft_init(data);
    create_thread(data);
    while(1);
}