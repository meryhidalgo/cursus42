/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:21:23 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/04/12 12:23:23 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_continue(t_philo *philo)
{
	pthread_mutex_lock(&philo->dstatus);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(&philo->dstatus), 1);
	pthread_mutex_unlock(&philo->dstatus);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	if (p->id % 2 == 0)
		ft_usleep(1);
	while (ft_continue(p) == 0)
	{
		eat(p);
		fsleep(p);
		think(p);
	}
	return (philo);
}

void	*supervisor(void *data)
{
	t_philo			*philos;
	t_program		*program;

	program = (t_program *) data;
	philos = program->philos;
	while (1)
	{
		if ((check_eaten(philos, program) == 1)
			|| (philo_death(philos, program) == 1))
			break ;
	}
	return (data);
}

int	main(int argc, char **argv)
{
	int				i;
	t_philo			*philos;
	t_program		program;
	pthread_t		thread;
	struct timeval	ini;

	gettimeofday(&ini, 0);
	if (init_program(argc, argv, &program) < 0)
		return (-1);
	philos = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	init_philo(argc, philos, argv, ini.tv_sec * 1000 + ini.tv_usec / 1000, program);
	program.philos = philos;
	if (pthread_create(&thread, NULL, supervisor, &program) != 0)
	{
		printf("Error creating the thread");
		return (-1);
	}
	i = 0;
	while (i < program.nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
			return (msg_error("Error creating the thread"));
		i++;
	}
	i = 0;
	if (pthread_join(thread, NULL) != 0)
	{
		printf("Error joining the thread");
		return (-1);
	}
	while (i < program.nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			printf("Error joining the thread");
			return (-1);
		}
		i++;
	}
	//end_program(philos, program);
	return (0);
}
