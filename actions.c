/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:09:21 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/12/05 15:56:11 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->next_fork);
		print_action(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->own_fork);
		print_action(philo->data, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->own_fork);
		print_action(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->next_fork);
		print_action(philo->data, philo->id, "has taken a fork");
	}
	philo->last_meal = ft_get_time(philo->data);
	print_action(philo->data, philo->id, "is eating");
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(philo->own_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_action(philo->data, philo->id, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo);
}

void	ft_think(t_philo *philo)
{
	print_action(philo->data, philo->id, "is thinking");
}

int	ft_dead(t_philo *philo)
{
	// if ((size_t)ft_time_without_eat(philo) >= philo->data->time_to_die)
	// {
	// 	// print_action(philo->data, philo->id, "died");
	// 	pthread_mutex_lock(&philo->data->mutex);
	// 	if (philo->data->dead)
	// 	{
	// 		pthread_mutex_unlock(&philo->data->mutex);
	// 		return (0);	
	// 	}
	// 	pthread_mutex_unlock(&philo->data->mutex);
	// 	return (0);
	// }
	// else
	// 	return (1);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (1);
}

