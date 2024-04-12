/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:21:23 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/04/12 13:46:13 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_continue(t_philo *philo)
{
	pthread_mutex_lock(philo->dstatus);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dstatus), 1);
	pthread_mutex_unlock(philo->dstatus);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *) philo;
	if (p->total_philos == 1)
	{
		pthread_mutex_lock(p->r_fork);
		display_message(FORK, p, p->ini, p->id);
		ft_usleep(p->time_to_die);
		pthread_mutex_unlock(p->r_fork);
		return (philo);
	}
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

int	threads(t_philo *philos, t_program program)
{
	int			i;
	pthread_t	thread;

	if (pthread_create(&thread, NULL, supervisor, &program) != 0)
		return (end_program(philos, program, "Error creating the thread"));
	i = 0;
	while (i < program.nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, routine, &philos[i]) != 0)
			return (end_program(philos, program, "Error creating the thread"));
		i++;
	}
	i = 0;
	if (pthread_join(thread, NULL) != 0)
		return (end_program(philos, program, "Error joining the thread"));
	while (i < program.nb_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (end_program(philos, program, "Error joining the thread"));
		i++;
	}
	return (end_program(philos, program, NULL));
}

int	main(int argc, char **argv)
{
	long int		time;
	t_philo			*philos;
	t_program		program;
	struct timeval	ini;

	gettimeofday(&ini, 0);
	if (init_program(argc, argv, &program) == 1)
		return (1);
	philos = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	init_argv(argc, argv, philos);
	time = ini.tv_sec * 1000 + ini.tv_usec / 1000;
	if (init_philo(philos, time, program) == 1)
		return (1);
	program.philos = philos;
	return (threads(philos, program));
}
