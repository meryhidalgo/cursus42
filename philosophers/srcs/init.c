/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:37 by mcarazo-          #+#    #+#             */
/*   Updated: 2024/04/12 12:23:35 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philo(int argc, t_philo *philos, char **argv, long int ini, t_program program)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].status = -1;
		philos[i].total_philos = ft_atoi(argv[1]);
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].meals_eaten = 0;
		if (argc > 5)
			philos[i].num_times_to_eat = ft_atoi(argv[5]);
		else
			philos[i].num_times_to_eat = -1;
		philos[i].last_eating = ini;
		philos[i].ini = ini;
		philos[i].dead = &program.death_ph;
		if (pthread_mutex_init(&philos[i].l_fork, NULL) != 0)
			return (-1);
		if (i > 0)
			philos[i].r_fork = &(philos[i - 1].l_fork);
		pthread_mutex_init(&philos[i].dstatus, NULL);
		pthread_mutex_init(&philos[i].mstatus, NULL);
		pthread_mutex_init(&philos[i].stat, NULL);
		pthread_mutex_init(&philos[i].last, NULL);
		/*if (pthread_mutex_init(&philos[i].dstatus, NULL) != 0
			|| pthread_mutex_init(&philos[i].mstatus, NULL) != 0
			|| pthread_mutex_init(&philos[i].stat, NULL) != 0
			|| pthread_mutex_init(&philos[i].last, NULL) != 0)
			return (-1);*/
		i++;
	}
	philos[0].r_fork = &(philos[i - 1].l_fork);
	return (0);
}

int	init_program(int argc, char **argv, t_program *program)
{
	if (checker(argc, argv) == 1)
		return (-1);
	program->nb_philo = ft_atoi(argv[1]);
	program->death_ph = 0;
	//program->eaten_ph = 0;
	/*if (argc > 5)
		program->nb_meals = ft_atoi(argv[5]);
	else
		program->nb_meals = -1;*/
	/*if (pthread_mutex_init(&program->mwrite, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&program->ewrite, NULL) != 0)
		return (-1);*/
	//program->philos = philos;
	return (0);
}
