/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:23:58 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/12/17 20:41:11 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//MANAGE DEATH

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

//MANAGE FOOD

int	is_philo_satisfied(t_philo *philo)
{
	if (philo->meals >= philo->data->times_ate)
		return (1);
	return(0);
}

int	is_everyone_satisfied(t_data *data)
{
	int	i;

	if (data->times_ate < 0)
		return (0);
	i = 0;
	while (i < data->number_of_philo)
	{
		if (!is_philo_satisfied(&data->philo[i]))
			return (0);
		i++;
	}
	data->full= 1;
	return (1);
}
