/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:23:58 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/12/12 17:15:36 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_is_dead(t_data *data)
{
	pthread_mutex_lock(&data->mutex);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex);
	return (0);
}

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	if ((size_t)ft_time_without_eat(philo) > philo->data->time_to_die)
	{
		print_action(philo->data, philo->id, "died");	
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex);
	return (0);
}

int	is_anyone_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (is_philo_dead(&data->philo[i]))
			return (1);
		i++;
	}
	return (0);
}