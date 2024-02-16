/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:59:16 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/02/16 12:52:40 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Consider the philosophers to be processes and the chopsticks to be a shared resource.
Every process needs two resources out of which one it has already acquired and the other 
is acquired by some other process. Till the other process does not free the resource, 
this process cannot proceed.

https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788
https://www.geeksforgeeks.org/dining-philosophers-problem/
https://github.com/TommyJD93/Philosophers
*/

#include "../inc/philo.h"

int	philo_death(t_philo *philo)
{
	struct timeval	t;
	long int		now;

	gettimeofday(&t, 0);
	now = t.tv_sec * 1000 + t.tv_usec / 1000;
	if (now - philo->last_eating > philo->time_to_die)
		return (1);
	else
		return (0);
}

long int	ft_time(t_philo	*p)
{
	long int		time;
	struct timeval	e;

	gettimeofday(&e, 0);
	time = e.tv_sec * 1000 + e.tv_usec / 1000 - p->ini;
	return (time);
}

void	*routine(void *philo)
{
	struct timeval	e;
	t_philo			*p;

	p = (t_philo *)philo;
	while (philo_death(p) == 0)
	{
		pthread_mutex_lock(&p->l_fork);
		pthread_mutex_lock(p->r_fork);
		printf("%ld %i has taken a fork\n", ft_time(p), p->id);
		p->status = 0;
		printf("%ld %i is eating\n", ft_time(p), p->id);
		usleep(p->time_to_eat);
		gettimeofday(&e, 0);
		p->last_eating = e.tv_sec * 1000 + e.tv_usec / 1000;
		pthread_mutex_unlock(&p->l_fork);
		pthread_mutex_unlock(p->r_fork);
		if (p->status <= 0)
		{
			p->status = 1;
			printf("%ld %i is sleeping\n", ft_time(p), p->id);
			usleep(p->time_to_sleep);
			p->status = 2;
			printf("%ld %i is thinking\n", ft_time(p), p->id);
		}
	}
	printf("Philo %i died", p->id);
	//pthread_mutex_destroy(&p->l_fork);
	//exit(0);
	return (philo); // or data
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

int	main(int argc, char **argv)
{
	int				i;
	int				nb_philo;
	t_philo			*philos;
	int				thread_rc;
	struct timeval	ini;

	gettimeofday(&ini, 0);
	if (checker(argc, argv) == 1)
		return (-1);
	nb_philo = ft_atoi(argv[1]);
	philos = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
	init_philo(philos, argv, ini.tv_sec * 1000 + ini.tv_usec / 1000);
	i = 0;
	while (i < nb_philo)
	{
		thread_rc = pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		if (thread_rc != 0)
		{
			printf("Error creating the thread. Code %i", thread_rc);
			return (-1);
		}
		/*if (pthread_detach(philos[i].thread) != 0)
		{
			printf("pthread_detach() error. Code %i", thread_rc);
			return (-1);
		}*/
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&philos[i].l_fork);
	}
	printf("[MAIN:%ld]: Thread return\n", (long)pthread_self());
	free(philos);
}



