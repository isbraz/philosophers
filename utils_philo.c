/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:21:52 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/12/28 23:22:52 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_data *data, int id, char *action)
{
	pthread_mutex_lock(&data->write_lock);
	pthread_mutex_lock(&data->dead_lock);
	if (!data->dead)
		printf("%ld %d %s\n", ft_get_time(data), id, action);
	pthread_mutex_unlock(&data->dead_lock);
	pthread_mutex_unlock(&data->write_lock);
}

int	ft_time_without_eat(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->meal_lock);
	time = ft_get_time(philo->data) - philo->last_meal;
	pthread_mutex_unlock(&philo->meal_lock);
	return (time);
}
