/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:18:40 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/11/23 14:56:21 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_philo *philo, t_data *data, int id)
{
	philo->id = id + 1;
	philo->last_meal = 0;
	philo->data = data;
	philo->own_fork = &data->forks[id];
	if (id == data->number_of_philo - 1)
		philo->next_fork = &data->forks[0];
	else
		philo->next_fork = &data->forks[id + 1];
}

void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	while (i < data->number_of_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
}

int	ft_init_argvs(int ac,char **argv, t_data *data)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 \
	|| ft_atoi(argv[4]) < 0)
		return (0);
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (ac == 6)
		data->n_philo_eat = ft_atoi(argv[5]);
	data->init_time = 0;
	data->init_time = ft_get_time(data);
	return (1);
}


	// int				id;
	// size_t			last_meal;
	// pthread_t		ph;
	// int				left_fork;	
	// int				right_fork;
	// pthread_mutex_t	meal_lock;