/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:09:21 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/11/22 18:02:33 by isbraz-d         ###   ########.fr       */
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
		pthread_mutex_lock(philo->next_fork);
		print_action(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->own_fork);
		print_action(philo->data, philo->id, "has taken a fork");
	}
	philo->last_meal = ft_get_time();
	print_action(philo->data, philo->id, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(philo->own_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_action(philo->data, philo->id, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	print_action(philo->data, philo->id, "is thinking");
}

int	ft_dead(t_philo *philo)
{
	if (ft_time_without_eat(philo) >= philo->data->time_to_die)
	{
		print_action(philo->data, philo->id, "died");
		return (0);
	}
	return (1);
}

//to make the dead function we need :
// 1 check the time (see if have time to eat)
//se o tempo de espera ate voltar a comer for igual ou maior :
// o philo morre.
// how to get o tempo que fico sem comer