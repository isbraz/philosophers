/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:23:58 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/11/27 16:28:24 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_is_dead(t_data *data)
{
	int	philo_dead;

	philo_dead = 0;
	pthread_mutex_lock(&data->mutex);
	if (data->dead)
		philo_dead = 1;
	pthread_mutex_unlock(&data->mutex);
	return (philo_dead);
}

void	ft_unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(philo->own_fork);
}
