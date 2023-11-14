/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:09:21 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/11/14 14:39:58 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eating(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo->data, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo->data, philo->id, "has taken a fork");
	}
	
}

void	ft_sleeping()
{
	
}

void	ft_thinking()
{
	
}