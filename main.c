/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:15:43 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/11/06 16:33:05 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>


void *thread_function(void *arg)
{
    // Código a ser executado pela thread
	int *int_ptr = (int *)arg; 
    printf("Thread executando: %d\n", *int_ptr);
    return NULL;
}

int main() 
{
	pthread_t *thread_id2;
	int teste = 0;

	thread_id2 = malloc(sizeof(pthread_t) * 5);
	int i = 0;
    // Cria uma nova thread
	while(i < 5)
    {	
		pthread_create(&thread_id2[i++], NULL, thread_function, &teste);
		teste++;
	}
	i = 0;
	while(i < 5)
	{
   		pthread_join(thread_id2[i++], NULL);
		printf("matou\n");
	}
    return 0;
}