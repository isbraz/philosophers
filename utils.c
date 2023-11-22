/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:22:03 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/11/22 18:05:53 by isbraz-d         ###   ########.fr       */
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

long int	ft_get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((long long)(tv.tv_sec) * 1000 + (long long)(tv.tv_usec) / 1000);
}

void	print_action(t_data *data, int id, char *action)
{
	pthread_mutex_lock(&data->write_lock);
	printf("%ld %d %s\n", ft_get_time() - data->init_time, id, action);
	pthread_mutex_unlock(&data->write_lock);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(200);
	return (0);
}

int	ft_time_without_eat(t_philo *philo)
{
	long int	time_now;

	time_now = ft_get_time() - philo->data->init_time;
	return (time_now - philo->last_meal);
}