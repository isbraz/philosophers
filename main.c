/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:15:43 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/11/09 13:53:15 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	mutex;

void *thread_function(void *arg)
{
    pthread_mutex_lock(&mutex);
    int *int_ptr = (int *)arg; 
    printf("Thread executando: %d\n", *int_ptr);
    pthread_mutex_unlock(&mutex);
    free(int_ptr);
    return (NULL);
}

int main() 
{
    pthread_t *thread_id2;
    t_data	data;

    thread_id2 = malloc(sizeof(pthread_t) * 5);
    pthread_mutex_init(&mutex, NULL);
    int i = 0;
    // Cria uma nova thread
    while(i < 5)
    {
        int *teste = malloc(sizeof(int));
        *teste = i;
        pthread_create(&thread_id2[i], NULL, thread_function, teste);
        i++;
    }
    i = 0;
    while(i < 5)
    {
		pthread_join(thread_id2[i], NULL);
		printf("matou\n");
		i++;
    }
    pthread_mutex_destroy(&mutex);
    free(thread_id2);
    return (0);
}
