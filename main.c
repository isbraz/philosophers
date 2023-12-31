/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:15:43 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/12/17 21:02:01 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_dead(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (arg);
}

int main(int ac, char **argv)
{
	t_data			data;
	int	i;

	ft_init_argvs(ac, argv, &data);
	init_mutexes(&data);
	data.philo = malloc(sizeof(t_philo) * data.number_of_philo);
	if (!data.philo)
		return (0);
	i = 0;
	init_forks(&data);
	while (i < data.number_of_philo)
	{
		init_philo(&data.philo[i], &data, i);
		pthread_create(&data.philo[i].ph, NULL, (void *)ft_routine, &data.philo[i]);
		i++;
	}
	i = 0;
	while (!is_anyone_dead(&data) && (!is_everyone_satisfied(&data)))
		usleep(500);
	while (i < data.number_of_philo)
	{
		pthread_join(data.philo[i].ph, NULL);
		i++;
	}
	ft_quit(&data);
	return (0);
}

//se um philo esta comendo o philo+1 nao pode comer e se o philo atual for o ultimo, o primeiro nao pode comer


//routine : 

// pthread_mutex_t	mutex;

// void *thread_function(void *arg)
// {
//     pthread_mutex_lock(&mutex);
//     int *int_ptr = (int *)arg; 
//     printf("Thread executando: %d\n", *int_ptr);
//     pthread_mutex_unlock(&mutex);
//     free(int_ptr);
//     return (NULL);
// }


// args : number_of_philo | time_to_die  | time_to_eat | time_to_sleep | [number_of_times_each_philosopher_must_eat]

// int main() 
// {
//     pthread_t *thread_id2;
//     t_data	data;

//     thread_id2 = malloc(sizeof(pthread_t) * 5);
//     pthread_mutex_init(&mutex, NULL);
//     int i = 0;
//     // Cria uma nova thread
//     while(i < 5)
//     {
//         int *teste = malloc(sizeof(int));
//         *teste = i;
//         pthread_create(&thread_id2[i], NULL, thread_function, teste);
//         i++;
//     }
//     i = 0;
//     while(i < 5)
//     {
// 		pthread_join(thread_id2[i], NULL);
// 		printf("matou\n");
// 		i++;
//     }
//     pthread_mutex_destroy(&mutex);
//     free(thread_id2);
//     return (0);
// }