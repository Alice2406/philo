/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:02 by aniezgod          #+#    #+#             */
/*   Updated: 2023/03/22 14:31:47 by aniezgod         ###   ########.fr       */
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
