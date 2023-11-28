/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:22:03 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/11/28 18:42:18 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoi(const char *str)
{
	long	result;
	int		negative;
	int		i;

	result = 0;
	i = 0;
	negative = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-')
		negative *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (result == 0)
			result = str[i] - 48;
		else
			result = ((result * 10) + (str[i] - 48));
		i++;
	}
	return (result * negative);
}

size_t	ft_get_time(t_data *data)
{
	size_t		now;
	struct timeval	time;

	gettimeofday(&time, NULL);
	now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (now - (data->init_time));
}

void	print_action(t_data *data, int id, char *action)
{
	pthread_mutex_lock(&data->write_lock);
	if (!data->dead)
		printf("%ld %d %s\n", ft_get_time(data), id, action);
	if (action[0] == 'd')
		data->dead = 1;
	pthread_mutex_unlock(&data->write_lock);
}

int	ft_usleep(size_t time, t_philo *philo)
{
	size_t	start;

	start = ft_get_time(philo->data);
	while ((ft_get_time(philo->data) - start) < time)
		usleep(200);
	return (0);
}

int	ft_time_without_eat(t_philo *philo)
{
	return (ft_get_time(philo->data) - philo->last_meal);
}

