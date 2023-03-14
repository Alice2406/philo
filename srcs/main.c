/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:11:35 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/14 14:51:55 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	compteur;
	int	number;

	i = 0;
	compteur = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			compteur = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * compteur);
}

int ft_check_param(char **av, int ac)
{
    if (ac == 6 && ft_atoi(av[5]) < 0)
        return (0);
    if (ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
        || ft_atoi(av[4]) > 0)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    t_data *data;

    if (ac != 6 && ac != 5)
        return (0);
    else
    {
        if(!ft_check_param(av, ac))
            return (0);
    }
    data = malloc(sizeof(t_data));
    if (!data)
        ft_error("malloc struct failed", NULL, 0);
    data->philo = malloc(sizeof(t_philo));
    if (!data->philo)
        ft_error("malloc struct failed", data, 0);
    data->nb_philo = ft_atoi(av[1]);
    ft_init(data);
}