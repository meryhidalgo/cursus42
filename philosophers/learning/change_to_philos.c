/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:31:15 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/02/16 12:42:42 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "../inc/philo.h"

pthread_mutex_t	mutex;

void	*thread_run(void* data)
{
	int	i;
	int	i_data;

	printf("[TH_ID:%ld]: Hello from the thread \n", (long)pthread_self());
	pthread_mutex_lock(&mutex);
	printf("[TH_ID:%ld]: Reading %i \n", (long)pthread_self(), (*(int *)data));
	i_data = (*(int *)data);
	i = 0;
	while (i < 5)
	{
		printf("%d\n", i_data);
		i_data++;
		i++;
	}
	(*(int *)data) = i_data;
	printf("[TH_ID:%ld]: Writing %i \n", (long)pthread_self(), (*(int *)data));
	pthread_mutex_unlock(&mutex);
	printf("[TH_ID: %ld]: To exit...............\n", (long)pthread_self());
	return (NULL);
}

int	init_philo(t_philo *philos, char **argv, long int ini)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].status = -1;
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]) * 1000;
		philos[i].time_to_sleep = ft_atoi(argv[4]) * 1000;
		philos[i].last_eating = ini;
		philos[i].ini = ini;
		if (pthread_mutex_init(&philos[i].l_fork, NULL) != 0)
			return (-1);
		if (i > 0)
			philos[i].r_fork = &(philos[i - 1].l_fork);
		i++;
	}
	philos[0].r_fork = &(philos[i - 1].l_fork);
	return (0);
}

int main(int argc, char **argv)
{
	int				i;
	pthread_t		thread[2];
	int				data;
	int				thread_rc;
	int				nb_philo;
	t_philo			*philos;
	struct timeval	ini;

	gettimeofday(&ini, 0);
	nb_philo = ft_atoi(argv[1]);
	philos = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
	init_philo(philos, argv, ini.tv_sec * 1000 + ini.tv_usec / 1000);

	data = 0;
	while (i < nb_philo)
	{
		printf("[MAIN:%ld]: Starting............ \n", (long)pthread_self());
		thread_rc = pthread_create(&philos[i].thread, NULL, thread_run, &data);
		if (thread_rc != 0)
		{
			printf("Error creating the thread. Code %i",thread_rc);
			return (-1);
		}
	}
	//sleep(1);
	printf("[MAIN:%ld]: Thread allocated \n", (long)pthread_self());
	for (i = 0; i < 2; i++)
		pthread_join(thread[i], NULL);
	pthread_mutex_destroy(&mutex);
	//sleep(1);
	printf("[MAIN:%ld]: Thread return\n", (long)pthread_self());
	//printf("[MAIN:%ld]: Thread returns %d \n", (long)pthread_self(), *ptr_output_data);
	return (0);
} 
