/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:27:05 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/12/12 17:15:40 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->mutex);
}

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(philo->own_fork);
}