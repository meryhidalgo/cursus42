/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:01:39 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/03/20 16:22:44 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//pthread_mutex_t	mutex;

typedef struct s_program
{
	int					nb_philo;
	pthread_mutex_t		mwrite;
}				t_program;

typedef struct s_philo
{
	int					id;
	t_program			program;
}				t_philo;

void	*thread_run(void* data)
{
	t_philo	*p;

	p = (t_philo *) data;
	sleep(2);
	printf("[TH_ID:%ld]: Hello from the thread \n", (long)pthread_self());
	pthread_mutex_lock(&p->program.mwrite);
	printf("[TH_ID:%ld]: Reading %i \n", (long)pthread_self(), p->id);
	//i_data = (*(int *)data);
	sleep(1); //It should be removed
	p->id++;
	//(*(int *)data) = i_data;
	printf("[TH_ID:%ld]: Writing %i \n", (long)pthread_self(), p->id);
	pthread_mutex_unlock(&p->program.mwrite);
	printf("[TH_ID: %ld]: To exit...............\n", (long)pthread_self());
	return (data);
}

int main()
{
	int				i;
	pthread_t		thread[2];
	t_philo			data;
	t_program		program;
	int				thread_rc;
	int				*ptr_output_data;

	data.id = 0;
	if (pthread_mutex_init(&program.mwrite,NULL)!=0) 
		return (-1);
	data.program = program;
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
	pthread_mutex_destroy(&program.mwrite);
	printf("[MAIN:%ld]: Thread returns %d \n", (long)pthread_self(), *ptr_output_data);
	return (0);
} 
