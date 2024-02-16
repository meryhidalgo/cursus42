/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:01:39 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/02/16 12:07:18 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t	mutex;

void	*thread_run(void* data)
{
	int	i_data;

	sleep(2);
	printf("[TH_ID:%ld]: Hello from the thread \n", (long)pthread_self());
	pthread_mutex_lock(&mutex);
	printf("[TH_ID:%ld]: Reading %i \n", (long)pthread_self(), (*(int *)data));
	i_data = (*(int *)data);
	sleep(1); //It should be removed
	i_data++;
	(*(int *)data) = i_data;
	printf("[TH_ID:%ld]: Writing %i \n", (long)pthread_self(), (*(int *)data));
	pthread_mutex_unlock(&mutex);
	printf("[TH_ID: %ld]: To exit...............\n", (long)pthread_self());
	return (data);
}

int main()
{
	int				i;
	pthread_t		thread[2];
	int				data;
	int				thread_rc;
	int				*ptr_output_data;

	data = 0;
	if (pthread_mutex_init(&mutex,NULL)!=0) 
		return (-1);
	for (i = 0;i < 2; i++)
	{
		printf("[MAIN:%ld]: Starting............ \n", (long)pthread_self());
		thread_rc = pthread_create(&thread[i], NULL, thread_run, &data);
		if (thread_rc != 0)
		{
			printf("Error creating the thread. Code %i",thread_rc);
			return (-1);
		}
	}
	//sleep(1);
	printf("[MAIN:%ld]: Thread allocated \n", (long)pthread_self());
	for (i = 0; i < 2; i++)
		pthread_join(thread[i],(void **)&ptr_output_data);
	pthread_mutex_destroy(&mutex);
	printf("[MAIN:%ld]: Thread returns %d \n", (long)pthread_self(), *ptr_output_data);
	return (0);
} 
